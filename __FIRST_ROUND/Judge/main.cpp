#include<bits/stdc++.h>
/* WARNING: Function: ___chkstk_ms replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl main(int _Argc,char **_Argv,char **_Env)

{
  long long **pplVar1;
  undefined *_Src;
  char *_Str1;
  long long **pplVar2;
  char cVar3;
  int iVar4;
  size_t sVar5;
  FILE *pFVar6;
  long long *plVar7;
  long long **this;
  long long **_Dst;
  undefined8 uVar8;
  vector<> *this_00;
  long long *plStack_581c8;
  undefined auStack_581c0 [24];
  undefined auStack_581a8 [16];
  long long **pplStack_58198;
  char *pcStack_58188;
  unsigned long long uStack_58180;
  char acStack_58178 [16];
  undefined *puStack_58168;
  undefined8 uStack_58160;
  undefined auStack_58158 [16];
  long long **pplStack_58148;
  long long *plStack_58140;
  long long *aplStack_58138 [2];
  basic_string<> abStack_58128 [8];
  unsigned long long uStack_58120;
  undefined *puStack_58108;
  unsigned long long uStack_58100;
  undefined auStack_580f8 [16];
  undefined *puStack_580e8;
  unsigned long long uStack_580e0;
  undefined auStack_580d8 [16];
  basic_string<> abStack_580c8 [32];
  long long *aplStack_580a8 [45069];
  
  __main();
  pcStack_58188 = acStack_58178;
  uStack_58180 = 0;
  puStack_58168 = auStack_58158;
  pplStack_58148 = aplStack_58138;
  acStack_58178[0] = '\0';
  uStack_58160 = 0;
  auStack_58158[0] = 0;
  aplStack_580a8[0] = (long long *)&DAT_00000015;
  pplStack_58148 =
       (long long **)
       std::__cxx11::basic_string<>::_M_create
                 ((basic_string<> *)&pplStack_58148,(unsigned long long *)aplStack_580a8,0);
  aplStack_58138[0] = aplStack_580a8[0];
  std::__cxx11::basic_string<>::_S_copy_chars((char *)pplStack_58148,"%Y-%m-%d.%H.%M.%S.rep","" );
  plStack_58140 = aplStack_580a8[0];
  *(char *)((long long)pplStack_58148 + (long long)aplStack_580a8[0]) = '\0';
  std::__cxx11::basic_string<>::basic_string(abStack_58128,(basic_string *)&pplStack_58148);
  puStack_58108 = auStack_580f8;
  this_00 = (vector<> *)0x0;
  uStack_58100 = 0;
  puStack_580e8 = auStack_580d8;
  auStack_580f8[0] = 0;
  uStack_580e0 = 0;
  auStack_580d8[0] = 0;
LAB_14028c0a8:
  iVar4 = getopt_long(_Argc,_Argv,"f:c:m:r:s:l:d:h",0,0);
  _Str1 = optarg;
  if (iVar4 != -1) {
    switch(iVar4) {
    case 99:
      sVar5 = strlen(optarg);
      std::__cxx11::basic_string<>::_M_replace
                ((basic_string<> *)&puStack_580e8,0,uStack_580e0,_Str1,sVar5);
      goto LAB_14028c0a8;
    case 100:
      sVar5 = strlen(optarg);
      std::__cxx11::basic_string<>::_M_replace
                ((basic_string<> *)&puStack_58108,0,uStack_58100,_Str1,sVar5);
      goto LAB_14028c0a8;
    default:
      std::__cxx11::basic_string<>::basic_string
                ((basic_string<> *)aplStack_580a8,(basic_string *)&puStack_58168);
      Usage(*_Argv,aplStack_580a8,&pplStack_58148);
      break;
    case 0x66:
      global_player_process_time_ms = strtol(optarg,(char **)aplStack_580a8,10);
      if (*(char *)aplStack_580a8[0] != '\0') {
        std::__cxx11::basic_string<>::append((basic_string<> *)&puStack_58168,"-f parse error\n" );
        goto LAB_14028c220;
      }
      goto LAB_14028c0a8;
    case 0x6c:
      iVar4 = strcmp(optarg,"DBG");
      if (iVar4 == 0) {
        g_logLevel = 5;
        goto LAB_14028c0a8;
      }
      iVar4 = strcmp(_Str1,"INFO");
      if (iVar4 == 0) {
        g_logLevel = 4;
        goto LAB_14028c0a8;
      }
      iVar4 = strcmp(_Str1,"WARN");
      if (iVar4 == 0) {
        g_logLevel = 3;
        goto LAB_14028c0a8;
      }
      iVar4 = strcmp(_Str1,"ERR");
      if (iVar4 == 0) {
        g_logLevel = 2;
        goto LAB_14028c0a8;
      }
      iVar4 = strcmp(_Str1,"ASSERT");
      if (iVar4 == 0) {
        g_logLevel = 1;
        goto LAB_14028c0a8;
      }
      iVar4 = strcmp(_Str1,"NONE");
      if (iVar4 == 0) {
        g_logLevel = 0;
        goto LAB_14028c0a8;
      }
      break;
    case 0x6d:
      sVar5 = strlen(optarg);
      std::__cxx11::basic_string<>::_M_replace
                ((basic_string<> *)&pcStack_58188,0,uStack_58180,_Str1,sVar5);
      goto LAB_14028c0a8;
    case 0x72:
      sVar5 = strlen(optarg);
      std::__cxx11::basic_string<>::_M_replace(abStack_58128,0,uStack_58120,_Str1,sVar5);
      goto LAB_14028c0a8;
    case 0x73: // '-s' rand_seed
      goto switchD_14028c0e9_caseD_73;
    }
    std::__cxx11::basic_string<>::append((basic_string<> *)&puStack_58168,"Unknown log level\n" );
LAB_14028c220:
    this_00 = (vector<> *)0x1;
    goto LAB_14028c0a8;
  }
  pFVar6 = fopen(pcStack_58188,"r");
  if (pFVar6 == (FILE *)0x0) {
    std::__cxx11::basic_string<>::append((basic_string<> *)&puStack_58168,"map not find\n");
LAB_14028c5d2:
    std::__cxx11::basic_string<>::basic_string
              ((basic_string<> *)aplStack_580a8,(basic_string *)&puStack_58168);
    uVar8 = Usage(*_Argv,aplStack_580a8,&pplStack_58148);
    std::__cxx11::basic_string<>::_M_dispose();
    std::vector<>::~vector(this_00);
    std::vector<>::~vector((vector<> *)&plStack_581c8);
    std::__cxx11::basic_string<>::_M_dispose();
    std::__cxx11::basic_string<>::_M_dispose();
    std::__cxx11::basic_string<>::_M_dispose();
    std::__cxx11::basic_string<>::_M_dispose();
    std::__cxx11::basic_string<>::_M_dispose();
    std::__cxx11::basic_string<>::_M_dispose();
                    /* WARNING: Subroutine does not return */
    _Unwind_Resume(uVar8);
  }
  if ((char)this_00 != '\0') goto LAB_14028c5d2;
  auStack_581c0._0_16_ = (undefined  [16])0x0;
  plVar7 = (long long *)operator.new(0x20);
  plVar7[1] = 0;
  *plVar7 = (long long)(plVar7 + 2);
  *(undefined *)(plVar7 + 2) = 0;
  auStack_581c0._8_8_ = plVar7 + 4;
  auStack_581c0._0_8_ = plVar7 + 4;
  plStack_581c8 = plVar7;
  std::__cxx11::basic_string<>::_M_assign((basic_string<> *)plVar7,(basic_string *)&puStack_580e 8);
  pplStack_58198 = (long long **)0x0;
  auStack_581a8 = (undefined  [16])0x0;
  this = (long long **)operator.new(0x20);
  _Src = (undefined *)*plVar7;
  plVar7 = (long long *)plVar7[1];
  pplVar1 = this + 4;
  _Dst = this + 2;
  *this = (long long *)_Dst;
  auStack_581a8._8_8_ = this;
  auStack_581a8._0_8_ = this;
  pplStack_58198 = pplVar1;
  if (plVar7 < (long long *)0x10) {
    pplVar2 = this;
    if (plVar7 == (long long *)0x1) {
      *(undefined *)(this + 2) = *_Src;
      goto LAB_14028c3af;
    }
    if (plVar7 == (long long *)0x0) goto LAB_14028c3af;
  }
  else {
    _Dst = (long long **)
           std::__cxx11::basic_string<>::_M_create
                     ((basic_string<> *)this,(unsigned long long *)aplStack_580a8,0);
    *this = (long long *)_Dst;
    this[2] = plVar7;
  }
  memcpy(_Dst,_Src,(size_t)plVar7);
  _Dst = (long long **)*this;
  pplVar2 = (long long **)auStack_581a8._0_8_;
LAB_14028c3af:
  auStack_581a8._0_8_ = pplVar2;
  this[1] = plVar7;
  *(undefined *)((long long)_Dst + (long long)plVar7) = 0;
  auStack_581a8._8_8_ = pplVar1;
  std::__cxx11::basic_string<>::basic_string(abStack_580c8,(basic_string *)&puStack_58108);
  World::World(aplStack_580a8,pFVar6,_Argc,_Argv,abStack_580c8,(vector<> *)auStack_581a8);
  std::__cxx11::basic_string<>::_M_dispose();
  iVar4 = 15000;
  std::vector<>::~vector((vector<> *)auStack_581a8);
  do {
    cVar3 = World::step();
    if (cVar3 == '\0') break;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  std::__cxx11::basic_string<>::basic_string(abStack_580c8,(basic_string *)abStack_58128);
  World::save_rep_str((World *)aplStack_580a8,abStack_580c8);
  std::__cxx11::basic_string<>::_M_dispose();
  World::print_player_money();
  World::~World((World *)aplStack_580a8);
  std::vector<>::~vector((vector<> *)&plStack_581c8);
  std::__cxx11::basic_string<>::_M_dispose();
  std::__cxx11::basic_string<>::_M_dispose();
  std::__cxx11::basic_string<>::_M_dispose();
  std::__cxx11::basic_string<>::_M_dispose();
  std::__cxx11::basic_string<>::_M_dispose();
  std::__cxx11::basic_string<>::_M_dispose();
  return 0;
switchD_14028c0e9_caseD_73:
  _global_random_engine = strtol(optarg,(char **)aplStack_580a8,10);
  _global_random_engine = _global_random_engine % 0x7fffffff;
  if (_global_random_engine == 0) {
    _global_random_engine = 1;
  }
  goto LAB_14028c0a8;
}

