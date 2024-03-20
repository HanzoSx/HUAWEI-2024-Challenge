
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* World::step() */

undefined8 World::step(void)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong clock_now;
  undefined4 *puVar5;
  int *piVar6;
  _iobuf *p_Var7;
  int iVar8;
  int *in_RCX;
  ulonglong uVar9;
  undefined8 uVar10;
  longlong lVar11;
  longlong *local_a8 [2];
  longlong local_98 [2];
  Frame local_88 [64];
  int local_48;
  
  clock_now = std::chrono::_V2::system_clock::now();
  lVar11 = *(longlong *)(in_RCX + 0x15fd2);
  iVar8 = *in_RCX;
  lVar3 = *(longlong *)(in_RCX + 0x15fd0);
  *in_RCX = iVar8 + 1;
  if (lVar3 != lVar11) {
    puVar5 = (undefined4 *)(lVar3 + 8);
    uVar9 = 0;
    do {
      if (iVar8 + 1 == puVar5[1]) {
        *puVar5 = 0;
      }
      uVar9 = uVar9 + 1;
      puVar5 = puVar5 + 0x1a;
    } while (uVar9 < (ulonglong)((lVar11 - lVar3 >> 3) * 0x4ec4ec4ec4ec4ec5));
  }


    simulate_boat_boat_moving();
    simulate_boat_berth_update();
    if (*(longlong *)(in_RCX + 0x15fe2) != *(longlong *)(in_RCX + 0x15fe4)) {
        *(longlong *)(in_RCX + 0x15fe4) = *(longlong *)(in_RCX + 0x15fe2);
    }
    replay_protocol::Frame::Frame(local_88,(Arena *)0x0,false);
    local_48 = *in_RCX;
    process_disappearing_item((World *)in_RCX,local_88);
    new_item[abi:cxx11]((Frame *)local_a8);
    write_player_input((World *)in_RCX,(basic_string *)local_a8);
    wait_player_output((World *)in_RCX,(longlong)global_player_process_time_ms);
    lVar11 = *(longlong *)(in_RCX + 0x15fc4);
    
    do
    {
        if (lVar11 == *(longlong *)(in_RCX + 0x15fc6))
        {
            update_all_instruction_queue();
            simulate_robot();
            simulate_boat_instruction_excution();
            simulate_boat_loading_item();
            lVar3 = *(longlong *)(in_RCX + 0x15fc6);
            for (lVar11 = *(longlong *)(in_RCX + 0x15fc4); lVar11 != lVar3; lVar11 = lVar11 + 0x178)
            {
                piVar6 = *(int **)(lVar11 + 0xa8);
                if (piVar6 == *(int **)(lVar11 + 0xb0)) {
                iVar8 = 0;
                }
                else {
                iVar8 = 0;
                do {
                    iVar1 = *piVar6;
                    piVar6 = piVar6 + 1;
                    iVar8 = iVar8 + *(int *)(*(longlong *)(in_RCX + 0x15fd6) + 0x2c + (longlong)iVar1 * 0 x30
                                            );
                } while (*(int **)(lVar11 + 0xb0) != piVar6);
                }
                *(int *)(lVar11 + 0x100) = iVar8;
            }
            update_rep((World *)in_RCX,local_88);
            lVar11 = std::chrono::_V2::system_clock::now();
            if (g_logLevel < 4)
            {
                uVar10 = 1;
            }
            else
            {
                iVar8 = *in_RCX;
                uVar2 = *(undefined4 *)(*(longlong *)(in_RCX + 0x15fc4) + 0x100);
                p_Var7 = (_iobuf *)(*(code *)__imp___acrt_iob_func)(2);
                uVar10 = 1;
                fprintf(p_Var7,
                        "[INFO]D:/workspace/cppcode/2024codeCraft0.2/preliminary_judge/World.cpp:%d|%s|world .step %d\t%lld ms, player money %d\n"
                    ,0x14e,&DAT_1402b1e1c,iVar8,(lVar11 - clock_now) / 1000000,uVar2);
            }
    LAB_14015c040:
            if (local_a8[0] != local_98) {
                operator.delete(local_a8[0],local_98[0] + 1);
            }
            replay_protocol::Frame::~Frame(local_88);
            return uVar10;
        }
        if (*(int *)(lVar11 + 0x70) - 4U < 2)
        {
            uVar10 = 0;
            goto LAB_14015c040;
        }
        lVar11 = lVar11 + 0x178;
    } while( true );
}

