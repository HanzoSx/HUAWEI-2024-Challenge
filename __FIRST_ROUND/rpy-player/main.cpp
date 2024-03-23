#include <iostream>
#include <fstream>
#include <vector>

#include <sstream>
#include <windows.h>

#include <SFML\Graphics.hpp>
#include <SFUI.hpp>
#include <GoogleLikeButton.hpp>


const float block = 7;
const sf::Color map_area[10] = {
    {0xd3, 0xd3, 0xd1},
    {0xc5, 0xd4, 0xc1},
    {0xee, 0xe5, 0xf8},
    {0xc9, 0xc0, 0xd3},
    {0xfa, 0xea, 0xd3},
    {0xea, 0xd0, 0xd1},
    {0xe6, 0xa4, 0xa4},
    {0xaa, 0xa2, 0xb1},
    {0xf1, 0xc0, 0x7c},
    {0xf6, 0xb5, 0x6a}
};
const sf::Color map_berth(50, 50, 120), map_wall(30, 30, 30), map_sea(200, 200, 255);

void PrintCurrentWorkingDirectory() {
    TCHAR buffer[MAX_PATH];
    DWORD dwRet = GetCurrentDirectory(MAX_PATH, buffer);
    if (dwRet == 0) {
        std::cerr << "Failed to get current directory. Error code: " << GetLastError() << std::endl;
        return;
    }
    std::cout << "Current working directory: " << buffer << std::endl;
}

bool OpenFile(std::string& FilePath)
{
    OPENFILENAMEW ofn;
    WCHAR szFile[260] = { 0 };

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = L"Replay Files\0*.rpy\0\0"; // 双null终止
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;
    ofn.lpstrInitialDir = L".\\rpy"; // 设置初始目录

    if (GetOpenFileNameW(&ofn) == TRUE)
    {
        std::wstring wstrFilePath = ofn.lpstrFile;
        FilePath.assign(wstrFilePath.begin(), wstrFilePath.end()); // 转换为std::string

        return true;
    }
    else 
        return false;
}

sf::Font font;

class Drawer
{
public:

    static void Rect(sf::RenderTarget &window, float x, float y, float width, float height, float outline, sf::Color fill_c, sf::Color outline_c)
    {
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(width, height));
        rect.setOrigin(
            rect.getLocalBounds().width / 2,
            rect.getLocalBounds().height / 2
        );
        rect.setPosition(x, y);

        rect.setFillColor(fill_c);
        rect.setOutlineThickness(outline);
        rect.setOutlineColor(outline_c);

        window.draw(rect);
    }

    static void Circle(sf::RenderTarget &window, float x, float y, float radius, float outline, sf::Color fill_c, sf::Color outline_c)
    {
        sf::CircleShape circle;
        circle.setRadius(radius);
        circle.setOrigin(
            circle.getLocalBounds().width / 2,
            circle.getLocalBounds().height / 2
        );
        circle.setPosition(x, y);

        circle.setFillColor(fill_c);
        circle.setOutlineThickness(outline);
        circle.setOutlineColor(outline_c);

        window.draw(circle);
    }

    static void Text(sf::RenderTarget &window, float x, float y, sf::String str, sf::Color color, float size)
    {
        sf::Text text;
        text.setFont(font);
        text.setString(str);
        text.setCharacterSize(size);
        text.setOrigin(
            text.getLocalBounds().width / 2,
            text.getLocalBounds().height / 2
        );
        text.setPosition(x, y);

        text.setFillColor(color);

        window.draw(text);
    }

    static void line(sf::RenderWindow &window, float x1, float y1, float x2, float y2, sf::Color color)
    {
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(sqrt(powf(x1 - x2, 2) + powf(y1 - y2, 2)), 2));
        rect.setOrigin(
            rect.getLocalBounds().width / 2,
            rect.getLocalBounds().height / 2
        );
        rect.setPosition((x1 + x2) / 2, (y1 + y2) / 2);
        rect.setRotation(atan2(y1 - y2, x1 - x2) * 180 / 3.1415926535);

        rect.setFillColor(color);

        window.draw(rect);
    }

};


class TButton
{
public:

    sfu::GoogleLikeButton button;

    TButton() : button(m_sprite, 50, 0) {}
    TButton(std::string path) : TButton()
    {
        addTexture(path);
    }

    void addTexture(std::string path)
    {
        m_texture.push_back(sf::Texture());
        m_texture.back().loadFromFile(path);

        if (m_texture.size() == 1) setTexture(0);
    }

    void setTexture(size_t index)
    {
        m_sprite.setTexture(m_texture.at(index));
        float scale = std::min(
            (button.getRadius() * 2 + button.getWidth()) * 0.65
                / m_texture.at(index).getSize().x,
            (button.getRadius() * 2) * 0.65
                / m_texture.at(index).getSize().y
        );
        m_sprite.setScale(scale, scale);
        m_sprite.setOrigin(
            m_sprite.getLocalBounds().width / 2,
            m_sprite.getLocalBounds().height / 2
        );
        m_sprite.setPosition(
            button.getRadius() + button.getWidth() / 2,
            button.getRadius()
        );
    }

private:
    
    std::vector<sf::Texture> m_texture;
    sf::Sprite m_sprite;

};

const float BaseSpeed = 50;
bool play = false;
int speed = 10;

class TimeBar
{
public:

    void draw(sf::RenderWindow &window)
    {
        float _width = width * ((float)tick / total_tick);
        Drawer::Rect(window, 1950, 100, 1000, 50, 3, sf::Color::White, sf::Color(100, 100, 100));
        Drawer::Rect(window, 1950 - width / 2 + _width / 2, 100, _width, 50, 0, sf::Color::Black, sf::Color());
        Drawer::Text(window, 2300, 50, std::to_string(tick) + " / " + std::to_string(total_tick), sf::Color::Black, 25);
    }

    void handleEvent(sf::Event &event)
    {
        switch (event.type)
        {
            case sf::Event::EventType::MouseMoved:
            {
                sf::Vector2f pos(event.mouseMove.x, event.mouseMove.y);
                inbound = sf::FloatRect(1950 - width / 2 - 10, 75, width + 20, 50).contains(pos);
                posx = pos.x;
                break;
            }
            
            default:
                break;
        }
        if (inbound and sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            tick = total_tick * (posx - (1950 - width / 2)) / width;
            play = false;
        }
        if (tick < 1) tick = 1;
        if (tick > total_tick) tick = total_tick;
    }

    void Play(int dtick)
    {
        tick += dtick;
        if (tick < 1) tick = 1;
        if (tick > total_tick) tick = total_tick;
    }

    int Tick() { return tick;}

private:

    const static int total_tick = 15000;
    const static float width;// = 1000;
    int tick;

    bool inbound;
    float posx;

}   timebar;
const float TimeBar::width = 1000.f;

struct Data
{
public:

    static char map[200][200];

    int score;
    struct Goods
    {
        int x, y, val;
    };
    std::vector<Goods> goods;

    struct Robot
    {
        int x, y, goods;
        int goodsx, goodsy;
        int berthx, berthy;
    };
    std::vector<Robot> robot;

}   data[15000];
char Data::map[200][200];

sf::RenderTexture mapTexture;
sf::Texture mapT;
sf::Sprite mapS;

void ReadFile()
{
    std::string Path;
    if (!OpenFile(Path)) return;

    std::ifstream file;
    file.open(Path);

    for (int x = 0; x < 200; ++ x)
    {
        for (int y = 0; y < 200; ++ y)
            file.get(Data::map[x][y]);
        file.get();
    }
    
    int tick, item_num;
    while (file >> tick)
    {
        file >> data[tick].score;
        file >> item_num; // goods
        while (item_num --)
        {
            Data::Goods it;
            file >> it.x >> it.y >> it.val;

            // it.color1.r = 0x00 + int((double)val / 200 * (0xff - 0x00));
            // it.color1.g = 0xff + int((double)val / 200 * (0x00 - 0xff));
            // it.color1.b = 0x33 + int((double)val / 200 * (0x00 - 0x33));
            // it.color1.a = 255;

            data[tick].goods.push_back(it);
        }

        item_num = 10; // robot
        while (item_num --)
        {
            Data::Robot it;
            file >> it.x >> it.y >> it.goods;
            file >> it.goodsx >> it.goodsy;
            file >> it.berthx >> it.berthy;

            // it.color1 = sf::Color(0, 0, 0, 0);
            // if (goods > 0)
            //     it.color2 = sf::Color(0x00, 0xee, 0xff);
            // else
            //     it.color2 = sf::Color(0x60, 0x60, 0x60);

            data[tick].robot.push_back(it);
        }
    }

    file.close();


    // mapTexture.create(100, 100);
    mapTexture.create(block * 200, block * 200);
    for (int x = 0; x < 200; ++ x)
    for (int y = 0; y < 200; ++ y)
    {
        sf::Color tmpC;
        if (Data::map[x][y] >= '0' and Data::map[x][y] <= '9') tmpC = map_area[Data::map[x][y] - '0'];
        if (Data::map[x][y] == 'B') tmpC = map_berth;
        if (Data::map[x][y] == '#') tmpC = map_wall;
        if (Data::map[x][y] == '*') tmpC = map_sea;

        Drawer::Rect(mapTexture, block * (0.5 + y), block * (0.5 + x), block, block, 0, tmpC, sf::Color());
    }
    mapTexture.display();
    mapT = mapTexture.getTexture();
    mapS.setTexture(mapT);
    
}


int main(int argc, char const *argv[])
{

    font.loadFromFile("DENG.TTF");
    
    sf::VideoMode mode(2500, 1400);

    sfu::Window UIwindow;
    UIwindow.creat(mode, "Replay", sf::Style::Titlebar | sf::Style::Close);
    sf::RenderWindow& window = UIwindow.getWindow();

    sf::Vector2u screenSize = sf::Vector2u(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    unsigned int windowX = (screenSize.x - mode.width) / 2;
    unsigned int windowY = (screenSize.y - mode.height) / 2 * 0.4;
    window.setPosition(sf::Vector2i(windowX, windowY));

    ReadFile();

    TButton playB("icon\\play.png"),
            nextB("icon\\next.png"),
            prevB("icon\\prev.png"),
            jpnextB("icon\\jump_next.png"),
            jpprevB("icon\\jump_prev.png"),
            fileB("icon\\file.png");

    playB.addTexture("icon\\pause.png");
    playB.setTexture(1);

    UIwindow.push_back(playB.button);
    UIwindow.push_back(nextB.button);
    UIwindow.push_back(prevB.button);
    UIwindow.push_back(jpnextB.button);
    UIwindow.push_back(jpprevB.button);
    UIwindow.push_back(fileB.button);

    const int mPosX = 1950, mPosY = 180, Bwidth = 110;
    jpprevB.button.setViewPosition(sf::Vector2f(mPosX - 2*Bwidth, mPosY));
    prevB.button.setViewPosition(sf::Vector2f(mPosX - Bwidth, mPosY));
    playB.button.setViewPosition(sf::Vector2f(mPosX, mPosY));
    nextB.button.setViewPosition(sf::Vector2f(mPosX + Bwidth, mPosY));
    jpnextB.button.setViewPosition(sf::Vector2f(mPosX + 2*Bwidth, mPosY));

    fileB.button.setViewPosition(sf::Vector2f(mPosX + 4*Bwidth, mPosY));

    sf::Clock clock;
    clock.restart();
    while (window.isOpen())
    {
        if (play)
        {
            int tmp = BaseSpeed * speed / 10 * clock.getElapsedTime().asSeconds();
            if (tmp != 0)
            {
                clock.restart();
                timebar.Play(tmp);
            }
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::EventType::Closed:
                    window.close();
                    break;
                
                default:
                    break;
            }
            UIwindow.handleEvent(event);

            if (playB.button.isPressed(sf::Mouse::Left))
            {
                play = !play;
                if (play)
                {
                    clock.restart();
                }
            }
            timebar.handleEvent(event);
            playB.setTexture(play ? 0 : 1);

            if (nextB.button.isPressed(sf::Mouse::Left))
            {
                clock.restart();
                if (play) speed += 5;
                    else timebar.Play(1);
            }
            if (prevB.button.isPressed(sf::Mouse::Left))
            {
                clock.restart();
                if (play) speed -= 5;
                    else timebar.Play(-1);
            }
            if (jpnextB.button.isPressed(sf::Mouse::Left))
            {
                clock.restart();
                if (play) speed *= 2;
                    else timebar.Play(10);
            }
            if (jpprevB.button.isPressed(sf::Mouse::Left))
            {
                clock.restart();
                if (play) speed /= 2;
                    else timebar.Play(-10);
            }

            if (fileB.button.isPressed(sf::Mouse::Left))
                ReadFile();
        }
        

        window.clear(sf::Color::White);
        window.draw(UIwindow);

        window.setView(window.getDefaultView());

        timebar.draw(window);
        Drawer::Text(
            window, 2100, 50,
            std::to_string(speed / 10) + "." + std::to_string(speed % 10) + " X",
            sf::Color::Black, 25
        );

        // map
        window.draw(mapS);
        for (auto it : data[timebar.Tick()].goods)
        {
            sf::Color color;
            color.r = 0x00 + int((double)it.val / 200 * (0xff - 0x00));
            color.g = 0xff + int((double)it.val / 200 * (0x00 - 0xff));
            color.b = 0x33 + int((double)it.val / 200 * (0x00 - 0x33));
            color.a = 255;
            Drawer::Rect(
                window,
                block * (0.5 + it.y),
                block * (0.5 + it.x),
                block * 0.7, block * 0.7, 0, color, sf::Color()
            );
        }

        for(auto it : data[timebar.Tick()].robot)
        {
            sf::Color color;
            if (it.goods > 0)
                color = sf::Color(0x00, 0xaa, 0xdd);
            else
                color = sf::Color(0x00, 0x00, 0x00);
            Drawer::Circle(
                window,
                block * (0.5 + it.y),
                block * (0.5 + it.x),
                block / 2 * 0.7, block * 0.35,
                sf::Color(0, 0, 0, 0),
                color//, sf::Color()
            );

            Drawer::line(window, (0.5+it.y) * block, (0.5+it.x) * block, (0.5+it.goodsy) * block, (0.5+it.goodsx) * block, sf::Color(100, 100, 100, 100));
            Drawer::line(window, (0.5+it.y) * block, (0.5+it.x) * block, (0.5+it.berthy) * block, (0.5+it.berthx) * block, sf::Color(100, 100, 100, 100));
        }

        window.display();
        sf::sleep(sf::milliseconds(10));

    }
    
    

    return 0;
}
