
/* World::new_item[abi:cxx11](replay_protocol::Frame&) */

Frame * World::new_item[abi:cxx11](Frame *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint new_item_x;
  uint new_item_y;
  uint uVar5;
  uint new_item_val;
  uint uVar7;
  Vec2 *pVVar8;
  longlong *plVar9;
  longlong **pplVar10;
  Item *pIVar11;
  longlong **pplVar12;
  longlong lVar13;
  uint uVar14;
  int *in_RDX;
  ulonglong uVar15;
  ulonglong uVar16;
  longlong **pplVar17;
  longlong **pplVar18;
  undefined8 *puVar19;
  longlong in_R8;
  undefined8 *puVar20;
  ulonglong uVar21;
  int *piVar22;
  uint uVar23;
  uint uVar24;
  char *pcVar25;
  char cVar26;
  longlong local_res18;
  longlong **local_190;
  longlong ***local_188;
  longlong **local_180;
  uint local_178;
  uint local_16c;
  uint local_15c;
  longlong *local_158;
  ulonglong local_150;
  longlong local_148 [2];
  longlong **local_138;
  ulonglong local_130;
  longlong *local_128 [2];
  longlong **local_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined local_60;
  undefined7 uStack_5f;
  undefined uStack_58;
  undefined8 local_57;
  
  local_180 = (longlong **)(param_1 + 0x10);
  param_1[0x10] = (Frame)0x0;
  *(longlong ***)param_1 = local_180;
  *(undefined8 *)(param_1 + 8) = 0;
  if ((new_item[abi:cxx11](replay_protocol::Frame&)::item_num == '\0') &&
     (iVar2 = __cxa_guard_acquire(&new_item[abi:cxx11](replay_protocol::Frame&)::item_num),
     iVar2 != 0)) {
    DAT_14032cca0 = (uint *)0x0;
    new_item[abi:cxx11](replay_protocol::Frame&)::item_num._0_4_ = 0;
    new_item[abi:cxx11](replay_protocol::Frame&)::item_num._4_4_ = 0;
    DAT_14032cc98 = (uint *)0x0;
    atexit((_func_5014 *)&::__tcf_0);
    __cxa_guard_release(&new_item[abi:cxx11](replay_protocol::Frame&)::item_num);
  }
  if (*in_RDX == 1) {
    local_190 = local_128;
    local_138 = local_190;
    std::__cxx11::basic_string<>::_M_construct((basic_string<> *)&local_138,1,'-');
    local_res18 = in_R8;
    local_188 = &local_138;
    *(undefined *)local_138 = 0x35;
    plVar9 = (longlong *)
             std::__cxx11::basic_string<>::_M_replace_aux
                       ((basic_string<> *)&local_138,local_130,0,1,'\n');
    pplVar12 = (longlong **)(plVar9 + 2);
    if ((longlong **)*plVar9 == pplVar12) {
      uVar21 = plVar9[1] + 1;
      pplVar18 = pplVar12;
      pplVar10 = (longlong **)&uStack_108;
      if (7 < (uint)uVar21) {
        uVar15 = 0;
        do {
          new_item_x = (int)uVar15 + 8;
          uVar16 = (ulonglong)new_item_x;
          *(undefined8 *)((longlong)&uStack_108 + uVar15) =
               *(undefined8 *)((longlong)pplVar12 + uVar15);
          uVar15 = uVar16;
        } while (new_item_x < ((uint)uVar21 & 0xfffffff8));
        pplVar10 = (longlong **)((longlong)&uStack_108 + uVar16);
        pplVar18 = (longlong **)(uVar16 + (longlong)pplVar12);
      }
      lVar13 = 0;
      if ((uVar21 & 4) != 0) {
        *(undefined4 *)pplVar10 = *(undefined4 *)pplVar18;
        lVar13 = 4;
      }
      if ((uVar21 & 2) != 0) {
        *(undefined2 *)((longlong)pplVar10 + lVar13) = *(undefined2 *)((longlong)pplVar18 + lVar1 3);
        lVar13 = lVar13 + 2;
      }
      local_118 = (longlong **)&uStack_108;
      if ((uVar21 & 1) != 0) {
        *(undefined *)((longlong)pplVar10 + lVar13) = *(undefined *)((longlong)pplVar18 + lVar13 );
      }
    }
    else {
      uStack_108 = (longlong *)plVar9[2];
      local_118 = (longlong **)*plVar9;
    }
    local_110 = (longlong *)plVar9[1];
    *(undefined *)(plVar9 + 2) = 0;
    *plVar9 = (longlong)pplVar12;
    plVar9[1] = 0;
    if (0x3fffffffffffffffU - *(longlong *)(param_1 + 8) < local_110) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::append");
    }
    std::__cxx11::basic_string<>::_M_append
              ((basic_string<> *)param_1,(char *)local_118,(ulonglong)local_110);
    if (local_118 != (longlong **)&uStack_108) {
      operator.delete(local_118,(longlong)uStack_108 + 1);
    }
    if (local_138 != local_190) {
      operator.delete(local_138,(longlong)local_128[0] + 1);
    }
    local_16c = 5;



    
    do {
      new_item_x = std::uniform_int_distribution<int>::operator()
                        ((uniform_int_distribution<int> *)&global_random_engine,
                         (linear_congruential_engine *)0x0,(param_type *)0xc7);
      new_item_y = std::uniform_int_distribution<int>::operator()
                        ((uniform_int_distribution<int> *)&global_random_engine,
                         (linear_congruential_engine *)0x0,(param_type *)0xc7);
      while( true ) {
        piVar22 = in_RDX + (longlong)(int)new_item_x * 200 + (longlong)(int)new_item_y;
        if ((piVar22[0x2744] == 0) &&
           (*(char *)((longlong)in_RDX + (longlong)(int)new_item_y + 8 + (longlong)(int)new_item_x * 0xc9) ==
            '.')) break;
        new_item_x = std::uniform_int_distribution<int>::operator()
                          ((uniform_int_distribution<int> *)&global_random_engine,
                           (linear_congruential_engine *)0x0,(param_type *)0xc7);
        new_item_y = std::uniform_int_distribution<int>::operator()
                          ((uniform_int_distribution<int> *)&global_random_engine,
                           (linear_congruential_engine *)0x0,(param_type *)0xc7);
      }
      new_item_val = std::uniform_int_distribution<int>::operator()
                        ((uniform_int_distribution<int> *)&global_random_engine,
                         (linear_congruential_engine *)0x1,(param_type *)0xc8);



      piVar22[0x2744] = new_item_val;
      uVar23 = -((int)new_item_x >> 0x1f);
      uVar21 = (ulonglong)(uVar23 & 0xff);
      uVar5 = -new_item_x;
      if (0 < (int)new_item_x) {
        uVar5 = new_item_x;
      }
      piVar22[0xc384] = *in_RDX + 1000;
      if (uVar5 < 10) {
        local_138 = local_190;
        std::__cxx11::basic_string<>::_M_construct
                  ((basic_string<> *)local_188,(ulonglong)(uVar23 + 1),'-');
        pcVar25 = (char *)(uVar21 + (longlong)local_138);
LAB_14015a74d:
        cVar26 = (char)uVar5 + '0';
      }
      else {
        if (uVar5 < 100) {
          local_138 = local_190;
          std::__cxx11::basic_string<>::_M_construct
                    ((basic_string<> *)local_188,(ulonglong)(uVar23 + 2),'-');
          local_118 = (longlong **)0x3330323031303030;
          pcVar25 = (char *)(uVar21 + (longlong)local_138);
          local_110 = (longlong *)0x3730363035303430;
          uStack_108 = (longlong *)0x3131303139303830;
          local_100 = 0x3531343133313231;
          local_f8 = 0x3931383137313631;
          local_f0 = 0x3332323231323032;
          local_e8 = 0x3732363235323432;
          local_e0 = 0x3133303339323832;
          local_d8 = 0x3533343333333233;
          local_d0 = 0x3933383337333633;
          local_c8 = 0x3334323431343034;
          local_c0 = 0x3734363435343434;
          local_b8 = 0x3135303539343834;
          local_b0 = 0x3535343533353235;
          local_a8 = 0x3935383537353635;
          local_a0 = 0x3336323631363036;
          local_98 = 0x3736363635363436;
          local_90 = 0x3137303739363836;
          local_88 = 0x3537343733373237;
          local_80 = 0x3937383737373637;
          local_78 = 0x3338323831383038;
          local_70 = 0x3738363835383438;
          local_60 = 0x39;
          local_68 = 0x3139303939383838;
          uStack_5f = 0x35393439333932;
          uStack_58 = 0x39;
          local_57 = 0x39393839373936;
        }
        else {
          if (uVar5 < 1000) {
            uVar24 = 2;
            iVar2 = 3;
          }
          else if (uVar5 < 10000) {
            uVar24 = 3;
            iVar2 = 4;
          }
          else {
            iVar2 = 5;
            if (uVar5 < 100000) {
LAB_14015b046:
              uVar24 = iVar2 - 1;
            }
            else if (uVar5 < 1000000) {
              uVar24 = 5;
LAB_14015a4e7:
              iVar2 = uVar24 + 1;
            }
            else {
              uVar24 = 6;
              iVar2 = 7;
              if (9999999 < uVar5) {
                if (99999999 < uVar5) {
                  if (uVar5 < 1000000000) {
                    iVar2 = 9;
                    goto LAB_14015b046;
                  }
                  uVar24 = 9;
                  goto LAB_14015a4e7;
                }
                uVar24 = 7;
                iVar2 = 8;
              }
            }
          }
          local_138 = local_190;
          std::__cxx11::basic_string<>::_M_construct
                    ((basic_string<> *)local_188,(ulonglong)(iVar2 + uVar23),'-');
          local_118 = (longlong **)0x3330323031303030;
          pcVar25 = (char *)(uVar21 + (longlong)local_138);
          local_110 = (longlong *)0x3730363035303430;
          uStack_108 = (longlong *)0x3131303139303830;
          local_100 = 0x3531343133313231;
          local_f8 = 0x3931383137313631;
          local_f0 = 0x3332323231323032;
          local_e8 = 0x3732363235323432;
          local_e0 = 0x3133303339323832;
          local_d8 = 0x3533343333333233;
          local_d0 = 0x3933383337333633;
          local_c8 = 0x3334323431343034;
          local_c0 = 0x3734363435343434;
          local_b8 = 0x3135303539343834;
          local_b0 = 0x3535343533353235;
          local_a8 = 0x3935383537353635;
          local_a0 = 0x3336323631363036;
          local_98 = 0x3736363635363436;
          local_90 = 0x3137303739363836;
          local_88 = 0x3537343733373237;
          local_80 = 0x3937383737373637;
          local_78 = 0x3338323831383038;
          local_70 = 0x3738363835383438;
          local_60 = 0x39;
          local_68 = 0x3139303939383838;
          uStack_5f = 0x35393439333932;
          uStack_58 = 0x39;
          local_57 = 0x39393839373936;
          uVar21 = (ulonglong)uVar5;
          do {
            uVar5 = (uint)(uVar21 / 100);
            uVar7 = (uint)uVar21;
            uVar14 = (uVar7 + uVar5 * -100) * 2;
            pcVar25[uVar24] = *(char *)((longlong)&local_118 + (ulonglong)(uVar14 + 1));
            uVar23 = uVar24 - 1;
            uVar24 = uVar24 - 2;
            pcVar25[uVar23] = *(char *)((longlong)&local_118 + (ulonglong)uVar14);
            uVar21 = uVar21 / 100;
          } while (9999 < uVar7);
          if (uVar7 < 1000) goto LAB_14015a74d;
        }
        local_57 = 0x39393839373936;
        uStack_58 = 0x39;
        uStack_5f = 0x35393439333932;
        local_60 = 0x39;
        local_68 = 0x3139303939383838;
        local_70 = 0x3738363835383438;
        local_78 = 0x3338323831383038;
        local_80 = 0x3937383737373637;
        local_88 = 0x3537343733373237;
        local_90 = 0x3137303739363836;
        local_98 = 0x3736363635363436;
        local_a0 = 0x3336323631363036;
        local_a8 = 0x3935383537353635;
        local_b0 = 0x3535343533353235;
        local_b8 = 0x3135303539343834;
        local_c0 = 0x3734363435343434;
        local_c8 = 0x3334323431343034;
        local_d0 = 0x3933383337333633;
        local_d8 = 0x3533343333333233;
        local_e0 = 0x3133303339323832;
        local_e8 = 0x3732363235323432;
        local_f0 = 0x3332323231323032;
        local_f8 = 0x3931383137313631;
        local_100 = 0x3531343133313231;
        uStack_108 = (longlong *)0x3131303139303830;
        local_110 = (longlong *)0x3730363035303430;
        local_118 = (longlong **)0x3330323031303030;
        pcVar25[1] = *(char *)((longlong)&local_118 + (ulonglong)(uVar5 * 2 + 1));
        cVar26 = *(char *)((longlong)&local_118 + (ulonglong)(uVar5 * 2));
      }
      *pcVar25 = cVar26;
      if (0x3fffffffffffffffU - *(longlong *)(param_1 + 8) < local_130) {
                    /* WARNING: Subroutine does not return */
        std::__throw_length_error("basic_string::append");
      }
      std::__cxx11::basic_string<>::_M_append((basic_string<> *)param_1,(char *)local_138,local_ 130)
      ;
      if (local_138 != local_190) {
        operator.delete(local_138,(longlong)local_128[0] + 1);
      }
      uVar21 = *(ulonglong *)(param_1 + 8);
      pplVar12 = *(longlong ***)param_1;
      if (local_180 == pplVar12) {
        uVar15 = 0xf;
      }
      else {
        uVar15 = *(ulonglong *)(param_1 + 0x10);
      }
      if (uVar15 < uVar21 + 1) {
        std::__cxx11::basic_string<>::_M_mutate((basic_string<> *)param_1,uVar21,0,(char *)0x0,1 );
        pplVar12 = *(longlong ***)param_1;
      }
      *(undefined *)((longlong)pplVar12 + uVar21) = 0x20;
      *(ulonglong *)(param_1 + 8) = uVar21 + 1;
      uVar5 = -((int)new_item_y >> 0x1f);
      uVar15 = (ulonglong)uVar5;
      *(undefined *)(*(longlong *)param_1 + 1 + uVar21) = 0;
      uVar23 = -new_item_y;
      if (0 < (int)new_item_y) {
        uVar23 = new_item_y;
      }
      if (uVar23 < 10) {
        local_138 = local_190;
        std::__cxx11::basic_string<>::_M_construct
                  ((basic_string<> *)local_188,(ulonglong)(uVar5 + 1),'-');
        pcVar25 = (char *)(uVar15 + (longlong)local_138);
LAB_14015aae5:
        cVar26 = (char)uVar23 + '0';
      }
      else {
        if (uVar23 < 100) {
          local_138 = local_190;
          std::__cxx11::basic_string<>::_M_construct
                    ((basic_string<> *)local_188,(ulonglong)(uVar5 + 2),'-');
          local_118 = (longlong **)0x3330323031303030;
          pcVar25 = (char *)(uVar15 + (longlong)local_138);
          local_110 = (longlong *)0x3730363035303430;
          uStack_108 = (longlong *)0x3131303139303830;
          local_100 = 0x3531343133313231;
          local_f8 = 0x3931383137313631;
          local_f0 = 0x3332323231323032;
          local_e8 = 0x3732363235323432;
          local_e0 = 0x3133303339323832;
          local_d8 = 0x3533343333333233;
          local_d0 = 0x3933383337333633;
          local_c8 = 0x3334323431343034;
          local_c0 = 0x3734363435343434;
          local_b8 = 0x3135303539343834;
          local_b0 = 0x3535343533353235;
          local_a8 = 0x3935383537353635;
          local_a0 = 0x3336323631363036;
          local_98 = 0x3736363635363436;
          local_90 = 0x3137303739363836;
          local_88 = 0x3537343733373237;
          local_80 = 0x3937383737373637;
          local_78 = 0x3338323831383038;
          local_70 = 0x3738363835383438;
          local_60 = 0x39;
          local_68 = 0x3139303939383838;
          uStack_5f = 0x35393439333932;
          uStack_58 = 0x39;
          local_57 = 0x39393839373936;
        }
        else {
          if (uVar23 < 1000) {
            uVar24 = 2;
            iVar2 = 3;
          }
          else if (uVar23 < 10000) {
            uVar24 = 3;
            iVar2 = 4;
          }
          else {
            iVar2 = 5;
            if (uVar23 < 100000) {
LAB_14015b024:
              uVar24 = iVar2 - 1;
            }
            else if (uVar23 < 1000000) {
              uVar24 = 5;
LAB_14015a87b:
              iVar2 = uVar24 + 1;
            }
            else {
              uVar24 = 6;
              iVar2 = 7;
              if (9999999 < uVar23) {
                if (99999999 < uVar23) {
                  if (uVar23 < 1000000000) {
                    iVar2 = 9;
                    goto LAB_14015b024;
                  }
                  uVar24 = 9;
                  goto LAB_14015a87b;
                }
                uVar24 = 7;
                iVar2 = 8;
              }
            }
          }
          local_138 = local_190;
          std::__cxx11::basic_string<>::_M_construct
                    ((basic_string<> *)local_188,(ulonglong)(iVar2 + uVar5),'-');
          local_118 = (longlong **)0x3330323031303030;
          pcVar25 = (char *)(uVar15 + (longlong)local_138);
          local_110 = (longlong *)0x3730363035303430;
          uStack_108 = (longlong *)0x3131303139303830;
          local_100 = 0x3531343133313231;
          local_f8 = 0x3931383137313631;
          local_f0 = 0x3332323231323032;
          local_e8 = 0x3732363235323432;
          local_e0 = 0x3133303339323832;
          local_d8 = 0x3533343333333233;
          local_d0 = 0x3933383337333633;
          local_c8 = 0x3334323431343034;
          local_c0 = 0x3734363435343434;
          local_b8 = 0x3135303539343834;
          local_b0 = 0x3535343533353235;
          local_a8 = 0x3935383537353635;
          local_a0 = 0x3336323631363036;
          local_98 = 0x3736363635363436;
          local_90 = 0x3137303739363836;
          local_88 = 0x3537343733373237;
          local_80 = 0x3937383737373637;
          local_78 = 0x3338323831383038;
          local_70 = 0x3738363835383438;
          local_60 = 0x39;
          local_68 = 0x3139303939383838;
          uStack_5f = 0x35393439333932;
          uStack_58 = 0x39;
          local_57 = 0x39393839373936;
          uVar21 = (ulonglong)uVar23;
          do {
            uVar23 = (uint)(uVar21 / 100);
            uVar7 = (uint)uVar21;
            uVar14 = (uVar7 + uVar23 * -100) * 2;
            pcVar25[uVar24] = *(char *)((longlong)&local_118 + (ulonglong)(uVar14 + 1));
            uVar5 = uVar24 - 1;
            uVar24 = uVar24 - 2;
            pcVar25[uVar5] = *(char *)((longlong)&local_118 + (ulonglong)uVar14);
            uVar21 = uVar21 / 100;
          } while (9999 < uVar7);
          if (uVar7 < 1000) goto LAB_14015aae5;
        }
        local_57 = 0x39393839373936;
        uStack_58 = 0x39;
        uStack_5f = 0x35393439333932;
        local_60 = 0x39;
        local_68 = 0x3139303939383838;
        local_70 = 0x3738363835383438;
        local_78 = 0x3338323831383038;
        local_80 = 0x3937383737373637;
        local_88 = 0x3537343733373237;
        local_90 = 0x3137303739363836;
        local_98 = 0x3736363635363436;
        local_a0 = 0x3336323631363036;
        local_a8 = 0x3935383537353635;
        local_b0 = 0x3535343533353235;
        local_b8 = 0x3135303539343834;
        local_c0 = 0x3734363435343434;
        local_c8 = 0x3334323431343034;
        local_d0 = 0x3933383337333633;
        local_d8 = 0x3533343333333233;
        local_e0 = 0x3133303339323832;
        local_e8 = 0x3732363235323432;
        local_f0 = 0x3332323231323032;
        local_f8 = 0x3931383137313631;
        local_100 = 0x3531343133313231;
        uStack_108 = (longlong *)0x3131303139303830;
        local_110 = (longlong *)0x3730363035303430;
        local_118 = (longlong **)0x3330323031303030;
        pcVar25[1] = *(char *)((longlong)&local_118 + (ulonglong)(uVar23 * 2 + 1));
        cVar26 = *(char *)((longlong)&local_118 + (ulonglong)(uVar23 * 2));
      }
      *pcVar25 = cVar26;
      if (0x3fffffffffffffffU - *(longlong *)(param_1 + 8) < local_130) {
                    /* WARNING: Subroutine does not return */
        std::__throw_length_error("basic_string::append");
      }
      std::__cxx11::basic_string<>::_M_append((basic_string<> *)param_1,(char *)local_138,local_ 130)
      ;
      if (local_138 != local_190) {
        operator.delete(local_138,(longlong)local_128[0] + 1);
      }
      uVar21 = *(ulonglong *)(param_1 + 8);
      pplVar12 = *(longlong ***)param_1;
      if (local_180 == pplVar12) {
        uVar15 = 0xf;
      }
      else {
        uVar15 = *(ulonglong *)(param_1 + 0x10);
      }
      if (uVar15 < uVar21 + 1) {
        std::__cxx11::basic_string<>::_M_mutate((basic_string<> *)param_1,uVar21,0,(char *)0x0,1 );
        pplVar12 = *(longlong ***)param_1;
      }
      *(undefined *)((longlong)pplVar12 + uVar21) = 0x20;
      *(ulonglong *)(param_1 + 8) = uVar21 + 1;
      uVar23 = -((int)new_item_val >> 0x1f);
      *(undefined *)(*(longlong *)param_1 + 1 + uVar21) = 0;
      uVar21 = (ulonglong)(uVar23 & 0xff);
      uVar5 = -new_item_val;
      if (0 < (int)new_item_val) {
        uVar5 = new_item_val;
      }
      if (uVar5 < 10) {
        local_138 = local_190;
        std::__cxx11::basic_string<>::_M_construct
                  ((basic_string<> *)local_188,(ulonglong)(uVar23 + 1),'-');
        pcVar25 = (char *)(uVar21 + (longlong)local_138);
LAB_14015ae7d:
        cVar26 = (char)uVar5 + '0';
      }
      else {
        if (uVar5 < 100) {
          local_138 = local_190;
          std::__cxx11::basic_string<>::_M_construct
                    ((basic_string<> *)local_188,(ulonglong)(uVar23 + 2),'-');
          local_118 = (longlong **)0x3330323031303030;
          pcVar25 = (char *)(uVar21 + (longlong)local_138);
          local_110 = (longlong *)0x3730363035303430;
          uStack_108 = (longlong *)0x3131303139303830;
          local_100 = 0x3531343133313231;
          local_f8 = 0x3931383137313631;
          local_f0 = 0x3332323231323032;
          local_e8 = 0x3732363235323432;
          local_e0 = 0x3133303339323832;
          local_d8 = 0x3533343333333233;
          local_d0 = 0x3933383337333633;
          local_c8 = 0x3334323431343034;
          local_c0 = 0x3734363435343434;
          local_b8 = 0x3135303539343834;
          local_b0 = 0x3535343533353235;
          local_a8 = 0x3935383537353635;
          local_a0 = 0x3336323631363036;
          local_98 = 0x3736363635363436;
          local_90 = 0x3137303739363836;
          local_88 = 0x3537343733373237;
          local_80 = 0x3937383737373637;
          local_78 = 0x3338323831383038;
          local_70 = 0x3738363835383438;
          local_60 = 0x39;
          local_68 = 0x3139303939383838;
          uStack_5f = 0x35393439333932;
          uStack_58 = 0x39;
          local_57 = 0x39393839373936;
        }
        else {
          if (uVar5 < 1000) {
            uVar24 = 2;
            iVar2 = 3;
          }
          else if (uVar5 < 10000) {
            uVar24 = 3;
            iVar2 = 4;
          }
          else {
            iVar2 = 5;
            if (uVar5 < 100000) {
LAB_14015b002:
              uVar24 = iVar2 - 1;
            }
            else if (uVar5 < 1000000) {
              uVar24 = 5;
LAB_14015ac14:
              iVar2 = uVar24 + 1;
            }
            else {
              uVar24 = 6;
              iVar2 = 7;
              if (9999999 < uVar5) {
                if (99999999 < uVar5) {
                  if (uVar5 < 1000000000) {
                    iVar2 = 9;
                    goto LAB_14015b002;
                  }
                  uVar24 = 9;
                  goto LAB_14015ac14;
                }
                uVar24 = 7;
                iVar2 = 8;
              }
            }
          }
          local_138 = local_190;
          std::__cxx11::basic_string<>::_M_construct
                    ((basic_string<> *)local_188,(ulonglong)(iVar2 + uVar23),'-');
          local_118 = (longlong **)0x3330323031303030;
          pcVar25 = (char *)(uVar21 + (longlong)local_138);
          local_110 = (longlong *)0x3730363035303430;
          uStack_108 = (longlong *)0x3131303139303830;
          local_100 = 0x3531343133313231;
          local_f8 = 0x3931383137313631;
          local_f0 = 0x3332323231323032;
          local_e8 = 0x3732363235323432;
          local_e0 = 0x3133303339323832;
          local_d8 = 0x3533343333333233;
          local_d0 = 0x3933383337333633;
          local_c8 = 0x3334323431343034;
          local_c0 = 0x3734363435343434;
          local_b8 = 0x3135303539343834;
          local_b0 = 0x3535343533353235;
          local_a8 = 0x3935383537353635;
          local_a0 = 0x3336323631363036;
          local_98 = 0x3736363635363436;
          local_90 = 0x3137303739363836;
          local_88 = 0x3537343733373237;
          local_80 = 0x3937383737373637;
          local_78 = 0x3338323831383038;
          local_70 = 0x3738363835383438;
          local_60 = 0x39;
          local_68 = 0x3139303939383838;
          uStack_5f = 0x35393439333932;
          uStack_58 = 0x39;
          local_57 = 0x39393839373936;
          uVar21 = (ulonglong)uVar5;
          do {
            uVar5 = (uint)(uVar21 / 100);
            uVar7 = (uint)uVar21;
            uVar14 = (uVar7 + uVar5 * -100) * 2;
            pcVar25[uVar24] = *(char *)((longlong)&local_118 + (ulonglong)(uVar14 + 1));
            uVar23 = uVar24 - 1;
            uVar24 = uVar24 - 2;
            pcVar25[uVar23] = *(char *)((longlong)&local_118 + (ulonglong)uVar14);
            uVar21 = uVar21 / 100;
          } while (9999 < uVar7);
          if (uVar7 < 1000) goto LAB_14015ae7d;
        }
        local_57 = 0x39393839373936;
        uStack_58 = 0x39;
        uStack_5f = 0x35393439333932;
        local_60 = 0x39;
        local_68 = 0x3139303939383838;
        local_70 = 0x3738363835383438;
        local_78 = 0x3338323831383038;
        local_80 = 0x3937383737373637;
        local_88 = 0x3537343733373237;
        local_90 = 0x3137303739363836;
        local_98 = 0x3736363635363436;
        local_a0 = 0x3336323631363036;
        local_a8 = 0x3935383537353635;
        local_b0 = 0x3535343533353235;
        local_b8 = 0x3135303539343834;
        local_c0 = 0x3734363435343434;
        local_c8 = 0x3334323431343034;
        local_d0 = 0x3933383337333633;
        local_d8 = 0x3533343333333233;
        local_e0 = 0x3133303339323832;
        local_e8 = 0x3732363235323432;
        local_f0 = 0x3332323231323032;
        local_f8 = 0x3931383137313631;
        local_100 = 0x3531343133313231;
        uStack_108 = (longlong *)0x3131303139303830;
        local_110 = (longlong *)0x3730363035303430;
        local_118 = (longlong **)0x3330323031303030;
        pcVar25[1] = *(char *)((longlong)&local_118 + (ulonglong)(uVar5 * 2 + 1));
        cVar26 = *(char *)((longlong)&local_118 + (ulonglong)(uVar5 * 2));
      }
      *pcVar25 = cVar26;
      if (0x3fffffffffffffffU - *(longlong *)(param_1 + 8) < local_130) {
                    /* WARNING: Subroutine does not return */
        std::__throw_length_error("basic_string::append");
      }
      std::__cxx11::basic_string<>::_M_append((basic_string<> *)param_1,(char *)local_138,local_ 130)
      ;
      if (local_138 != local_190) {
        operator.delete(local_138,(longlong)local_128[0] + 1);
      }
      uVar21 = *(ulonglong *)(param_1 + 8);
      pplVar12 = *(longlong ***)param_1;
      if (local_180 == pplVar12) {
        uVar15 = 0xf;
      }
      else {
        uVar15 = *(ulonglong *)(param_1 + 0x10);
      }
      if (uVar15 < uVar21 + 1) {
        std::__cxx11::basic_string<>::_M_mutate((basic_string<> *)param_1,uVar21,0,(char *)0x0,1 );
        pplVar12 = *(longlong ***)param_1;
      }
      *(undefined *)((longlong)pplVar12 + uVar21) = 10;
      *(ulonglong *)(param_1 + 8) = uVar21 + 1;
      *(undefined *)(*(longlong *)param_1 + 1 + uVar21) = 0;
      piVar22 = *(int **)(local_res18 + 0x38);
      if (piVar22 == (int *)0x0) {
LAB_14015b068:
        pIVar11 = google::protobuf::Arena::CreateMaybeMessage<>(*(Arena **)(local_res18 + 0x28)) ;
        lVar13 = google::protobuf::internal::RepeatedPtrFieldBase::AddOutOfLineHelper
                           ((RepeatedPtrFieldBase *)(local_res18 + 0x28),pIVar11);
      }
      else {
        iVar2 = *(int *)(local_res18 + 0x30);
        if (*piVar22 <= iVar2) goto LAB_14015b068;
        lVar13 = *(longlong *)(piVar22 + (longlong)iVar2 * 2 + 2);
        *(int *)(local_res18 + 0x30) = iVar2 + 1;
      }
      pVVar8 = (Vec2 *)operator.new(0x20);
      replay_protocol::Vec2::Vec2(pVVar8,(Arena *)0x0,false);
      uVar21 = *(ulonglong *)(lVar13 + 8);
      *(uint *)(pVVar8 + 0x10) = new_item_x;
      *(uint *)(pVVar8 + 0x14) = new_item_y;
      puVar19 = (undefined8 *)(uVar21 & 0xfffffffffffffffc);
      if ((uVar21 & 1) != 0) {
        puVar19 = (undefined8 *)*puVar19;
      }
      if (puVar19 == (undefined8 *)0x0) {
        if (*(Vec2 **)(lVar13 + 0x10) == (Vec2 *)0x0) {
          uVar21 = *(ulonglong *)(pVVar8 + 8);
        }
        else {
          replay_protocol::Vec2::~Vec2(*(Vec2 **)(lVar13 + 0x10));
          uVar21 = *(ulonglong *)(pVVar8 + 8);
        }
        if ((uVar21 & 2) == 0) goto LAB_14015af98;
      }
      else {
        uVar21 = *(ulonglong *)(pVVar8 + 8);
        if ((uVar21 & 2) == 0) {
LAB_14015af98:
          puVar20 = (undefined8 *)(uVar21 & 0xfffffffffffffffc);
          if ((uVar21 & 1) != 0) {
            puVar20 = (undefined8 *)*puVar20;
          }
          if (puVar19 == puVar20) goto LAB_14015afb0;
        }
        else {
          puVar20 = (undefined8 *)0x0;
        }
        pVVar8 = (Vec2 *)google::protobuf::internal::GetOwnedMessageInternal
                                   ((Arena *)puVar19,(MessageLite *)pVVar8,(Arena *)puVar20);
      }
LAB_14015afb0:
      local_16c = local_16c + -1;
      *(Vec2 **)(lVar13 + 0x10) = pVVar8;
      *(uint *)(lVar13 + 0x18) = new_item_val;
      *(undefined *)(lVar13 + 0x1c) = 1;
      if (local_16c == 0) {
        local_118 = (longlong **)((ulonglong)local_118 & 0xffffffff00000000);
        if (DAT_14032cc98 != DAT_14032cca0) {
          *DAT_14032cc98 = 0;
          DAT_14032cc98 = DAT_14032cc98 + 1;
          return param_1;
        }
        std::vector<>::_M_realloc_insert<int>
                  ((vector<> *)&new_item[abi:cxx11](replay_protocol::Frame&)::item_num,
                   (__normal_iterator)DAT_14032cc98,(int *)&local_118);
        return param_1;
      }
    } while( true );
  }















  iVar2 = std::uniform_int_distribution<int>::operator()
                    ((uniform_int_distribution<int> *)&global_random_engine,
                     (linear_congruential_engine *)0x0,(param_type *)0x7);
  local_15c = 0;
  local_178 = 1;
  while (iVar2 == 0) {
    local_15c = local_178;
    new_item_x = std::uniform_int_distribution<int>::operator()
                      ((uniform_int_distribution<int> *)&global_random_engine,
                       (linear_congruential_engine *)0x0,(param_type *)0xc7);
    new_item_y = std::uniform_int_distribution<int>::operator()
                      ((uniform_int_distribution<int> *)&global_random_engine,
                       (linear_congruential_engine *)0x0,(param_type *)0xc7);
    while( true ) {
      piVar22 = in_RDX + (longlong)(int)new_item_x * 200 + (longlong)(int)new_item_y;
      if ((piVar22[0x2744] == 0) &&
         (*(char *)((longlong)in_RDX + (longlong)(int)new_item_y + 8 + (longlong)(int)new_item_x * 0xc9) ==
          '.')) break;
      new_item_x = std::uniform_int_distribution<int>::operator()
                        ((uniform_int_distribution<int> *)&global_random_engine,
                         (linear_congruential_engine *)0x0,(param_type *)0xc7);
      new_item_y = std::uniform_int_distribution<int>::operator()
                        ((uniform_int_distribution<int> *)&global_random_engine,
                         (linear_congruential_engine *)0x0,(param_type *)0xc7);
    }
    iVar2 = std::uniform_int_distribution<int>::operator()
                      ((uniform_int_distribution<int> *)&global_random_engine,
                       (linear_congruential_engine *)0x0,(param_type *)0x7);
    if (iVar2 < 1) {
      uVar5 = std::uniform_int_distribution<int>::operator()
                        ((uniform_int_distribution<int> *)&global_random_engine,
                         (linear_congruential_engine *)0x1,(param_type *) 0x64);
    }
    else {
      uVar5 = std::uniform_int_distribution<int>::operator()
                        ((uniform_int_distribution<int> *)&global_random_engine,
                         (linear_congruential_engine *)0xb4,(param_type *)0xc8);
    }
    piVar22[0x2744] = uVar5;
    uVar23 = -((int)new_item_x >> 0x1f);
    uVar21 = (ulonglong)(uVar23 & 0xff);
    new_item_val = -new_item_x;
    if (0 < (int)new_item_x) {
      new_item_val = new_item_x;
    }
    piVar22[0xc384] = *in_RDX + 1000;
    local_138 = local_128;
    if (new_item_val < 10) {
      std::__cxx11::basic_string<>::_M_construct
                ((basic_string<> *)&local_138,(ulonglong)(uVar23 + 1),'-');
      pcVar25 = (char *)(uVar21 + (longlong)local_138);
LAB_140158a42:
      cVar26 = (char)new_item_val + '0';
    }
    else {
      if (new_item_val < 100) {
        std::__cxx11::basic_string<>::_M_construct
                  ((basic_string<> *)&local_138,(ulonglong)(uVar23 + 2),'-');
        pcVar25 = (char *)(uVar21 + (longlong)local_138);
        local_118 = (longlong **)0x3330323031303030;
        local_110 = (longlong *)0x3730363035303430;
        uStack_108 = (longlong *)0x3131303139303830;
        local_100 = 0x3531343133313231;
        local_f8 = 0x3931383137313631;
        local_f0 = 0x3332323231323032;
        local_e8 = 0x3732363235323432;
        local_e0 = 0x3133303339323832;
        local_d8 = 0x3533343333333233;
        local_d0 = 0x3933383337333633;
        local_c8 = 0x3334323431343034;
        local_c0 = 0x3734363435343434;
        local_b8 = 0x3135303539343834;
        local_b0 = 0x3535343533353235;
        local_a8 = 0x3935383537353635;
        local_a0 = 0x3336323631363036;
        local_98 = 0x3736363635363436;
        local_90 = 0x3137303739363836;
        local_88 = 0x3537343733373237;
        local_80 = 0x3937383737373637;
        local_78 = 0x3338323831383038;
        local_70 = 0x3738363835383438;
        local_60 = 0x39;
        local_68 = 0x3139303939383838;
        uStack_5f = 0x35393439333932;
        uStack_58 = 0x39;
        local_57 = 0x39393839373936;
      }
      else {
        if (new_item_val < 1000) {
          local_16c = 2;
          iVar2 = 3;
        }
        else if (new_item_val < 10000) {
          local_16c = 3;
          iVar2 = 4;
        }
        else {
          iVar2 = 5;
          if (new_item_val < 100000) {
LAB_14015980d:
            local_16c = iVar2 - 1;
          }
          else if (new_item_val < 1000000) {
            local_16c = 5;
LAB_1401587da:
            iVar2 = local_16c + 1;
          }
          else {
            local_16c = 6;
            iVar2 = 7;
            if (9999999 < new_item_val) {
              if (99999999 < new_item_val) {
                if (new_item_val < 1000000000) {
                  iVar2 = 9;
                  goto LAB_14015980d;
                }
                local_16c = 9;
                goto LAB_1401587da;
              }
              local_16c = 7;
              iVar2 = 8;
            }
          }
        }
        std::__cxx11::basic_string<>::_M_construct
                  ((basic_string<> *)&local_138,(ulonglong)(iVar2 + uVar23),'-');
        local_118 = (longlong **)0x3330323031303030;
        pcVar25 = (char *)(uVar21 + (longlong)local_138);
        local_110 = (longlong *)0x3730363035303430;
        uStack_108 = (longlong *)0x3131303139303830;
        local_100 = 0x3531343133313231;
        local_f8 = 0x3931383137313631;
        local_f0 = 0x3332323231323032;
        local_e8 = 0x3732363235323432;
        local_e0 = 0x3133303339323832;
        local_d8 = 0x3533343333333233;
        local_d0 = 0x3933383337333633;
        local_c8 = 0x3334323431343034;
        local_c0 = 0x3734363435343434;
        local_b8 = 0x3135303539343834;
        local_b0 = 0x3535343533353235;
        local_a8 = 0x3935383537353635;
        local_a0 = 0x3336323631363036;
        local_98 = 0x3736363635363436;
        local_90 = 0x3137303739363836;
        local_88 = 0x3537343733373237;
        local_80 = 0x3937383737373637;
        local_78 = 0x3338323831383038;
        local_70 = 0x3738363835383438;
        local_60 = 0x39;
        local_68 = 0x3139303939383838;
        uStack_5f = 0x35393439333932;
        uStack_58 = 0x39;
        local_57 = 0x39393839373936;
        uVar21 = (ulonglong)new_item_val;
        do {
          new_item_val = (uint)(uVar21 / 100);
          uVar24 = (uint)uVar21;
          uVar23 = (uVar24 + new_item_val * -100) * 2;
          pcVar25[local_16c] = *(char *)((longlong)&local_118 + (ulonglong)(uVar23 + 1));
          uVar14 = local_16c - 1;
          local_16c = local_16c - 2;
          pcVar25[uVar14] = *(char *)((longlong)&local_118 + (ulonglong)uVar23);
          uVar21 = uVar21 / 100;
        } while (9999 < uVar24);
        if (uVar24 < 1000) goto LAB_140158a42;
      }
      local_57 = 0x39393839373936;
      uStack_58 = 0x39;
      uStack_5f = 0x35393439333932;
      local_60 = 0x39;
      local_68 = 0x3139303939383838;
      local_70 = 0x3738363835383438;
      local_78 = 0x3338323831383038;
      local_80 = 0x3937383737373637;
      local_88 = 0x3537343733373237;
      local_90 = 0x3137303739363836;
      local_98 = 0x3736363635363436;
      local_a0 = 0x3336323631363036;
      local_a8 = 0x3935383537353635;
      local_b0 = 0x3535343533353235;
      local_b8 = 0x3135303539343834;
      local_c0 = 0x3734363435343434;
      local_c8 = 0x3334323431343034;
      local_d0 = 0x3933383337333633;
      local_d8 = 0x3533343333333233;
      local_e0 = 0x3133303339323832;
      local_e8 = 0x3732363235323432;
      local_f0 = 0x3332323231323032;
      local_f8 = 0x3931383137313631;
      local_100 = 0x3531343133313231;
      uStack_108 = (longlong *)0x3131303139303830;
      local_110 = (longlong *)0x3730363035303430;
      local_118 = (longlong **)0x3330323031303030;
      pcVar25[1] = *(char *)((longlong)&local_118 + (ulonglong)(new_item_val * 2 + 1));
      cVar26 = *(char *)((longlong)&local_118 + (ulonglong)(new_item_val * 2));
    }
    *pcVar25 = cVar26;
    if (0x3fffffffffffffffU - *(longlong *)(param_1 + 8) < local_130) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::append");
    }
    std::__cxx11::basic_string<>::_M_append((basic_string<> *)param_1,(char *)local_138,local_13 0);
    if (local_138 != local_128) {
      operator.delete(local_138,(longlong)local_128[0] + 1);
    }
    uVar21 = *(ulonglong *)(param_1 + 8);
    pplVar12 = *(longlong ***)param_1;
    if (local_180 == pplVar12) {
      uVar15 = 0xf;
    }
    else {
      uVar15 = *(ulonglong *)(param_1 + 0x10);
    }
    if (uVar15 < uVar21 + 1) {
      std::__cxx11::basic_string<>::_M_mutate((basic_string<> *)param_1,uVar21,0,(char *)0x0,1);
      pplVar12 = *(longlong ***)param_1;
    }
    *(undefined *)((longlong)pplVar12 + uVar21) = 0x20;
    *(ulonglong *)(param_1 + 8) = uVar21 + 1;
    *(undefined *)(*(longlong *)param_1 + 1 + uVar21) = 0;
    uVar23 = -((int)new_item_y >> 0x1f);
    new_item_val = -new_item_y;
    if (0 < (int)new_item_y) {
      new_item_val = new_item_y;
    }
    uVar21 = (ulonglong)(uVar23 & 0xff);
    if (new_item_val < 10) {
      local_138 = local_128;
      std::__cxx11::basic_string<>::_M_construct
                ((basic_string<> *)&local_138,(ulonglong)(uVar23 + 1),'-');
      pcVar25 = (char *)(uVar21 + (longlong)local_138);
LAB_140158dda:
      cVar26 = (char)new_item_val + '0';
    }
    else {
      if (new_item_val < 100) {
        local_138 = local_128;
        std::__cxx11::basic_string<>::_M_construct
                  ((basic_string<> *)&local_138,(ulonglong)(uVar23 + 2),'-');
        pcVar25 = (char *)(uVar21 + (longlong)local_138);
        local_118 = (longlong **)0x3330323031303030;
        local_110 = (longlong *)0x3730363035303430;
        uStack_108 = (longlong *)0x3131303139303830;
        local_100 = 0x3531343133313231;
        local_f8 = 0x3931383137313631;
        local_f0 = 0x3332323231323032;
        local_e8 = 0x3732363235323432;
        local_e0 = 0x3133303339323832;
        local_d8 = 0x3533343333333233;
        local_d0 = 0x3933383337333633;
        local_c8 = 0x3334323431343034;
        local_c0 = 0x3734363435343434;
        local_b8 = 0x3135303539343834;
        local_b0 = 0x3535343533353235;
        local_a8 = 0x3935383537353635;
        local_a0 = 0x3336323631363036;
        local_98 = 0x3736363635363436;
        local_90 = 0x3137303739363836;
        local_88 = 0x3537343733373237;
        local_80 = 0x3937383737373637;
        local_78 = 0x3338323831383038;
        local_70 = 0x3738363835383438;
        local_60 = 0x39;
        local_68 = 0x3139303939383838;
        uStack_5f = 0x35393439333932;
        uStack_58 = 0x39;
        local_57 = 0x39393839373936;
      }
      else {
        if (new_item_val < 1000) {
          local_16c = 2;
          iVar2 = 3;
        }
        else if (new_item_val < 10000) {
          local_16c = 3;
          iVar2 = 4;
        }
        else {
          iVar2 = 5;
          if (new_item_val < 100000) {
LAB_1401597e5:
            local_16c = iVar2 - 1;
          }
          else if (new_item_val < 1000000) {
            local_16c = 5;
LAB_140158b73:
            iVar2 = local_16c + 1;
          }
          else {
            local_16c = 6;
            iVar2 = 7;
            if (9999999 < new_item_val) {
              if (99999999 < new_item_val) {
                if (new_item_val < 1000000000) {
                  iVar2 = 9;
                  goto LAB_1401597e5;
                }
                local_16c = 9;
                goto LAB_140158b73;
              }
              local_16c = 7;
              iVar2 = 8;
            }
          }
        }
        local_138 = local_128;
        std::__cxx11::basic_string<>::_M_construct
                  ((basic_string<> *)&local_138,(ulonglong)(iVar2 + uVar23),'-');
        local_118 = (longlong **)0x3330323031303030;
        pcVar25 = (char *)(uVar21 + (longlong)local_138);
        local_110 = (longlong *)0x3730363035303430;
        uStack_108 = (longlong *)0x3131303139303830;
        local_100 = 0x3531343133313231;
        local_f8 = 0x3931383137313631;
        local_f0 = 0x3332323231323032;
        local_e8 = 0x3732363235323432;
        local_e0 = 0x3133303339323832;
        local_d8 = 0x3533343333333233;
        local_d0 = 0x3933383337333633;
        local_c8 = 0x3334323431343034;
        local_c0 = 0x3734363435343434;
        local_b8 = 0x3135303539343834;
        local_b0 = 0x3535343533353235;
        local_a8 = 0x3935383537353635;
        local_a0 = 0x3336323631363036;
        local_98 = 0x3736363635363436;
        local_90 = 0x3137303739363836;
        local_88 = 0x3537343733373237;
        local_80 = 0x3937383737373637;
        local_78 = 0x3338323831383038;
        local_70 = 0x3738363835383438;
        local_60 = 0x39;
        local_68 = 0x3139303939383838;
        uStack_5f = 0x35393439333932;
        uStack_58 = 0x39;
        local_57 = 0x39393839373936;
        uVar21 = (ulonglong)new_item_val;
        do {
          new_item_val = (uint)(uVar21 / 100);
          uVar24 = (uint)uVar21;
          uVar23 = (uVar24 + new_item_val * -100) * 2;
          pcVar25[local_16c] = *(char *)((longlong)&local_118 + (ulonglong)(uVar23 + 1));
          uVar14 = local_16c - 1;
          local_16c = local_16c - 2;
          pcVar25[uVar14] = *(char *)((longlong)&local_118 + (ulonglong)uVar23);
          uVar21 = uVar21 / 100;
        } while (9999 < uVar24);
        if (uVar24 < 1000) goto LAB_140158dda;
      }
      local_57 = 0x39393839373936;
      uStack_58 = 0x39;
      uStack_5f = 0x35393439333932;
      local_60 = 0x39;
      local_68 = 0x3139303939383838;
      local_70 = 0x3738363835383438;
      local_78 = 0x3338323831383038;
      local_80 = 0x3937383737373637;
      local_88 = 0x3537343733373237;
      local_90 = 0x3137303739363836;
      local_98 = 0x3736363635363436;
      local_a0 = 0x3336323631363036;
      local_a8 = 0x3935383537353635;
      local_b0 = 0x3535343533353235;
      local_b8 = 0x3135303539343834;
      local_c0 = 0x3734363435343434;
      local_c8 = 0x3334323431343034;
      local_d0 = 0x3933383337333633;
      local_d8 = 0x3533343333333233;
      local_e0 = 0x3133303339323832;
      local_e8 = 0x3732363235323432;
      local_f0 = 0x3332323231323032;
      local_f8 = 0x3931383137313631;
      local_100 = 0x3531343133313231;
      uStack_108 = (longlong *)0x3131303139303830;
      local_110 = (longlong *)0x3730363035303430;
      local_118 = (longlong **)0x3330323031303030;
      pcVar25[1] = *(char *)((longlong)&local_118 + (ulonglong)(new_item_val * 2 + 1));
      cVar26 = *(char *)((longlong)&local_118 + (ulonglong)(new_item_val * 2));
    }
    *pcVar25 = cVar26;
    if (0x3fffffffffffffffU - *(longlong *)(param_1 + 8) < local_130) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::append");
    }
    std::__cxx11::basic_string<>::_M_append((basic_string<> *)param_1,(char *)local_138,local_13 0);
    if (local_138 != local_128) {
      operator.delete(local_138,(longlong)local_128[0] + 1);
    }
    uVar21 = *(ulonglong *)(param_1 + 8);
    pplVar12 = *(longlong ***)param_1;
    if (local_180 == pplVar12) {
      uVar15 = 0xf;
    }
    else {
      uVar15 = *(ulonglong *)(param_1 + 0x10);
    }
    if (uVar15 < uVar21 + 1) {
      std::__cxx11::basic_string<>::_M_mutate((basic_string<> *)param_1,uVar21,0,(char *)0x0,1);
      pplVar12 = *(longlong ***)param_1;
    }
    *(undefined *)((longlong)pplVar12 + uVar21) = 0x20;
    *(ulonglong *)(param_1 + 8) = uVar21 + 1;
    *(undefined *)(*(longlong *)param_1 + 1 + uVar21) = 0;
    uVar23 = -((int)uVar5 >> 0x1f);
    new_item_val = -uVar5;
    if (0 < (int)uVar5) {
      new_item_val = uVar5;
    }
    uVar21 = (ulonglong)(uVar23 & 0xff);
    if (new_item_val < 10) {
      local_138 = local_128;
      std::__cxx11::basic_string<>::_M_construct
                ((basic_string<> *)&local_138,(ulonglong)(uVar23 + 1),'-');
      pcVar25 = (char *)(uVar21 + (longlong)local_138);
LAB_140159172:
      cVar26 = (char)new_item_val + '0';
    }
    else {
      if (new_item_val < 100) {
        local_138 = local_128;
        std::__cxx11::basic_string<>::_M_construct
                  ((basic_string<> *)&local_138,(ulonglong)(uVar23 + 2),'-');
        pcVar25 = (char *)(uVar21 + (longlong)local_138);
        local_118 = (longlong **)0x3330323031303030;
        local_110 = (longlong *)0x3730363035303430;
        uStack_108 = (longlong *)0x3131303139303830;
        local_100 = 0x3531343133313231;
        local_f8 = 0x3931383137313631;
        local_f0 = 0x3332323231323032;
        local_e8 = 0x3732363235323432;
        local_e0 = 0x3133303339323832;
        local_d8 = 0x3533343333333233;
        local_d0 = 0x3933383337333633;
        local_c8 = 0x3334323431343034;
        local_c0 = 0x3734363435343434;
        local_b8 = 0x3135303539343834;
        local_b0 = 0x3535343533353235;
        local_a8 = 0x3935383537353635;
        local_a0 = 0x3336323631363036;
        local_98 = 0x3736363635363436;
        local_90 = 0x3137303739363836;
        local_88 = 0x3537343733373237;
        local_80 = 0x3937383737373637;
        local_78 = 0x3338323831383038;
        local_70 = 0x3738363835383438;
        local_60 = 0x39;
        local_68 = 0x3139303939383838;
        uStack_5f = 0x35393439333932;
        uStack_58 = 0x39;
        local_57 = 0x39393839373936;
      }
      else {
        if (new_item_val < 1000) {
          local_16c = 2;
          iVar2 = 3;
        }
        else if (new_item_val < 10000) {
          local_16c = 3;
          iVar2 = 4;
        }
        else {
          iVar2 = 5;
          if (new_item_val < 100000) {
LAB_1401597bd:
            local_16c = iVar2 - 1;
          }
          else if (new_item_val < 1000000) {
            local_16c = 5;
LAB_140158f0b:
            iVar2 = local_16c + 1;
          }
          else {
            local_16c = 6;
            iVar2 = 7;
            if (9999999 < new_item_val) {
              if (99999999 < new_item_val) {
                if (new_item_val < 1000000000) {
                  iVar2 = 9;
                  goto LAB_1401597bd;
                }
                local_16c = 9;
                goto LAB_140158f0b;
              }
              local_16c = 7;
              iVar2 = 8;
            }
          }
        }
        local_138 = local_128;
        std::__cxx11::basic_string<>::_M_construct
                  ((basic_string<> *)&local_138,(ulonglong)(iVar2 + uVar23),'-');
        local_118 = (longlong **)0x3330323031303030;
        pcVar25 = (char *)(uVar21 + (longlong)local_138);
        local_110 = (longlong *)0x3730363035303430;
        uStack_108 = (longlong *)0x3131303139303830;
        local_100 = 0x3531343133313231;
        local_f8 = 0x3931383137313631;
        local_f0 = 0x3332323231323032;
        local_e8 = 0x3732363235323432;
        local_e0 = 0x3133303339323832;
        local_d8 = 0x3533343333333233;
        local_d0 = 0x3933383337333633;
        local_c8 = 0x3334323431343034;
        local_c0 = 0x3734363435343434;
        local_b8 = 0x3135303539343834;
        local_b0 = 0x3535343533353235;
        local_a8 = 0x3935383537353635;
        local_a0 = 0x3336323631363036;
        local_98 = 0x3736363635363436;
        local_90 = 0x3137303739363836;
        local_88 = 0x3537343733373237;
        local_80 = 0x3937383737373637;
        local_78 = 0x3338323831383038;
        local_70 = 0x3738363835383438;
        local_60 = 0x39;
        local_68 = 0x3139303939383838;
        uStack_5f = 0x35393439333932;
        uStack_58 = 0x39;
        local_57 = 0x39393839373936;
        uVar21 = (ulonglong)new_item_val;
        do {
          new_item_val = (uint)(uVar21 / 100);
          uVar24 = (uint)uVar21;
          uVar23 = (uVar24 + new_item_val * -100) * 2;
          pcVar25[local_16c] = *(char *)((longlong)&local_118 + (ulonglong)(uVar23 + 1));
          uVar14 = local_16c - 1;
          local_16c = local_16c - 2;
          pcVar25[uVar14] = *(char *)((longlong)&local_118 + (ulonglong)uVar23);
          uVar21 = uVar21 / 100;
        } while (9999 < uVar24);
        if (uVar24 < 1000) goto LAB_140159172;
      }
      local_57 = 0x39393839373936;
      uStack_58 = 0x39;
      uStack_5f = 0x35393439333932;
      local_60 = 0x39;
      local_68 = 0x3139303939383838;
      local_70 = 0x3738363835383438;
      local_78 = 0x3338323831383038;
      local_80 = 0x3937383737373637;
      local_88 = 0x3537343733373237;
      local_90 = 0x3137303739363836;
      local_98 = 0x3736363635363436;
      local_a0 = 0x3336323631363036;
      local_a8 = 0x3935383537353635;
      local_b0 = 0x3535343533353235;
      local_b8 = 0x3135303539343834;
      local_c0 = 0x3734363435343434;
      local_c8 = 0x3334323431343034;
      local_d0 = 0x3933383337333633;
      local_d8 = 0x3533343333333233;
      local_e0 = 0x3133303339323832;
      local_e8 = 0x3732363235323432;
      local_f0 = 0x3332323231323032;
      local_f8 = 0x3931383137313631;
      local_100 = 0x3531343133313231;
      uStack_108 = (longlong *)0x3131303139303830;
      local_110 = (longlong *)0x3730363035303430;
      local_118 = (longlong **)0x3330323031303030;
      pcVar25[1] = *(char *)((longlong)&local_118 + (ulonglong)(new_item_val * 2 + 1));
      cVar26 = *(char *)((longlong)&local_118 + (ulonglong)(new_item_val * 2));
    }
    *pcVar25 = cVar26;
    if (0x3fffffffffffffffU - *(longlong *)(param_1 + 8) < local_130) {
                    /* WARNING: Subroutine does not return */
      std::__throw_length_error("basic_string::append");
    }
    std::__cxx11::basic_string<>::_M_append((basic_string<> *)param_1,(char *)local_138,local_13 0);
    if (local_138 != local_128) {
      operator.delete(local_138,(longlong)local_128[0] + 1);
    }
    uVar21 = *(ulonglong *)(param_1 + 8);
    pplVar12 = *(longlong ***)param_1;
    if (local_180 == pplVar12) {
      uVar15 = 0xf;
    }
    else {
      uVar15 = *(ulonglong *)(param_1 + 0x10);
    }
    if (uVar15 < uVar21 + 1) {
      std::__cxx11::basic_string<>::_M_mutate((basic_string<> *)param_1,uVar21,0,(char *)0x0,1);
      pplVar12 = *(longlong ***)param_1;
    }
    *(undefined *)((longlong)pplVar12 + uVar21) = 10;
    *(ulonglong *)(param_1 + 8) = uVar21 + 1;
    *(undefined *)(*(longlong *)param_1 + 1 + uVar21) = 0;
    piVar22 = *(int **)(in_R8 + 0x38);
    if (piVar22 == (int *)0x0) {
LAB_140159830:
      pIVar11 = google::protobuf::Arena::CreateMaybeMessage<>(*(Arena **)(in_R8 + 0x28));
      lVar13 = google::protobuf::internal::RepeatedPtrFieldBase::AddOutOfLineHelper
                         ((RepeatedPtrFieldBase *)(in_R8 + 0x28),pIVar11);
    }
    else {
      iVar2 = *(int *)(in_R8 + 0x30);
      if (*piVar22 <= iVar2) goto LAB_140159830;
      lVar13 = *(longlong *)(piVar22 + (longlong)iVar2 * 2 + 2);
      *(int *)(in_R8 + 0x30) = iVar2 + 1;
    }
    pVVar8 = (Vec2 *)operator.new(0x20);
    replay_protocol::Vec2::Vec2(pVVar8,(Arena *)0x0,false);
    uVar21 = *(ulonglong *)(lVar13 + 8);
    *(uint *)(pVVar8 + 0x10) = new_item_x;
    *(uint *)(pVVar8 + 0x14) = new_item_y;
    puVar19 = (undefined8 *)(uVar21 & 0xfffffffffffffffc);
    if ((uVar21 & 1) != 0) {
      puVar19 = (undefined8 *)*puVar19;
    }
    if (puVar19 == (undefined8 *)0x0) {
      if (*(Vec2 **)(lVar13 + 0x10) == (Vec2 *)0x0) {
        uVar21 = *(ulonglong *)(pVVar8 + 8);
      }
      else {
        replay_protocol::Vec2::~Vec2(*(Vec2 **)(lVar13 + 0x10));
        uVar21 = *(ulonglong *)(pVVar8 + 8);
      }
      if ((uVar21 & 2) == 0) goto joined_r0x000140159f9f;
    }
    else {
      uVar21 = *(ulonglong *)(pVVar8 + 8);
      if ((uVar21 & 2) == 0) {
joined_r0x000140159f9f:
        puVar20 = (undefined8 *)(uVar21 & 0xfffffffffffffffc);
        if ((uVar21 & 1) != 0) {
          puVar20 = (undefined8 *)*puVar20;
        }
        if (puVar19 == puVar20) goto LAB_14015929d;
      }
      else {
        puVar20 = (undefined8 *)0x0;
      }
      pVVar8 = (Vec2 *)google::protobuf::internal::GetOwnedMessageInternal
                                 ((Arena *)puVar19,(MessageLite *)pVVar8,(Arena *)puVar20);
    }
LAB_14015929d:
    *(Vec2 **)(lVar13 + 0x10) = pVVar8;
    *(uint *)(lVar13 + 0x18) = uVar5;
    *(undefined *)(lVar13 + 0x1c) = 1;
    iVar2 = std::uniform_int_distribution<int>::operator()
                      ((uniform_int_distribution<int> *)&global_random_engine,
                       (linear_congruential_engine *)0x0,(param_type *)0x3);
    local_178 = local_178 + 1;
  }
  if (DAT_14032cc98 == DAT_14032cca0) {
    std::vector<>::_M_realloc_insert<int_const&>
              ((vector<> *)&new_item[abi:cxx11](replay_protocol::Frame&)::item_num,
               (__normal_iterator)DAT_14032cc98,(int *)&local_15c);
  }
  else {
    *DAT_14032cc98 = local_15c;
    DAT_14032cc98 = DAT_14032cc98 + 1;
  }
  new_item_y = -((int)local_15c >> 0x1f);
  new_item_x = -local_15c;
  if (0 < (int)local_15c) {
    new_item_x = local_15c;
  }
  uVar21 = (ulonglong)(new_item_y & 0xff);
  if (new_item_x < 10) {
    local_158 = local_148;
    std::__cxx11::basic_string<>::_M_construct
              ((basic_string<> *)&local_158,(ulonglong)(new_item_y + 1),'-');
    pcVar25 = (char *)((longlong)local_158 + uVar21);
LAB_1401595d7:
    cVar26 = (char)new_item_x + '0';
  }
  else {
    if (new_item_x < 100) {
      local_158 = local_148;
      std::__cxx11::basic_string<>::_M_construct
                ((basic_string<> *)&local_158,(ulonglong)(new_item_y + 2),'-');
      local_118 = (longlong **)0x3330323031303030;
      local_110 = (longlong *)0x3730363035303430;
      pcVar25 = (char *)((longlong)local_158 + uVar21);
      uStack_108 = (longlong *)0x3131303139303830;
      local_100 = 0x3531343133313231;
      local_f8 = 0x3931383137313631;
      local_f0 = 0x3332323231323032;
      local_e8 = 0x3732363235323432;
      local_e0 = 0x3133303339323832;
      local_d8 = 0x3533343333333233;
      local_d0 = 0x3933383337333633;
      local_c8 = 0x3334323431343034;
      local_c0 = 0x3734363435343434;
      local_b8 = 0x3135303539343834;
      local_b0 = 0x3535343533353235;
      local_a8 = 0x3935383537353635;
      local_a0 = 0x3336323631363036;
      local_98 = 0x3736363635363436;
      local_90 = 0x3137303739363836;
      local_88 = 0x3537343733373237;
      local_80 = 0x3937383737373637;
      local_78 = 0x3338323831383038;
      local_70 = 0x3738363835383438;
      local_60 = 0x39;
      local_68 = 0x3139303939383838;
      uStack_5f = 0x35393439333932;
      uStack_58 = 0x39;
      local_57 = 0x39393839373936;
    }
    else {
      if (new_item_x < 1000) {
        uVar5 = 2;
        iVar2 = 3;
      }
      else if (new_item_x < 10000) {
        uVar5 = 3;
        iVar2 = 4;
      }
      else {
        iVar2 = 5;
        if (new_item_x < 100000) {
LAB_14015a24a:
          uVar5 = iVar2 - 1;
        }
        else if (new_item_x < 1000000) {
          uVar5 = 5;
LAB_140159379:
          iVar2 = uVar5 + 1;
        }
        else {
          uVar5 = 6;
          iVar2 = 7;
          if (9999999 < new_item_x) {
            if (99999999 < new_item_x) {
              if (new_item_x < 1000000000) {
                iVar2 = 9;
                goto LAB_14015a24a;
              }
              uVar5 = 9;
              goto LAB_140159379;
            }
            uVar5 = 7;
            iVar2 = 8;
          }
        }
      }
      local_158 = local_148;
      std::__cxx11::basic_string<>::_M_construct
                ((basic_string<> *)&local_158,(ulonglong)(iVar2 + new_item_y),'-');
      local_118 = (longlong **)0x3330323031303030;
      local_110 = (longlong *)0x3730363035303430;
      pcVar25 = (char *)((longlong)local_158 + uVar21);
      uStack_108 = (longlong *)0x3131303139303830;
      local_100 = 0x3531343133313231;
      local_f8 = 0x3931383137313631;
      local_f0 = 0x3332323231323032;
      local_e8 = 0x3732363235323432;
      local_e0 = 0x3133303339323832;
      local_d8 = 0x3533343333333233;
      local_d0 = 0x3933383337333633;
      local_c8 = 0x3334323431343034;
      local_c0 = 0x3734363435343434;
      local_b8 = 0x3135303539343834;
      local_b0 = 0x3535343533353235;
      local_a8 = 0x3935383537353635;
      local_a0 = 0x3336323631363036;
      local_98 = 0x3736363635363436;
      local_90 = 0x3137303739363836;
      local_88 = 0x3537343733373237;
      local_80 = 0x3937383737373637;
      local_78 = 0x3338323831383038;
      local_70 = 0x3738363835383438;
      local_60 = 0x39;
      local_68 = 0x3139303939383838;
      uStack_5f = 0x35393439333932;
      uStack_58 = 0x39;
      local_57 = 0x39393839373936;
      uVar21 = (ulonglong)new_item_x;
      do {
        new_item_x = (uint)(uVar21 / 100);
        uVar23 = (uint)uVar21;
        new_item_val = (uVar23 + new_item_x * -100) * 2;
        pcVar25[uVar5] = *(char *)((longlong)&local_118 + (ulonglong)(new_item_val + 1));
        new_item_y = uVar5 - 1;
        uVar5 = uVar5 - 2;
        pcVar25[new_item_y] = *(char *)((longlong)&local_118 + (ulonglong)new_item_val);
        uVar21 = uVar21 / 100;
      } while (9999 < uVar23);
      if (uVar23 < 1000) goto LAB_1401595d7;
    }
    local_57 = 0x39393839373936;
    uStack_58 = 0x39;
    uStack_5f = 0x35393439333932;
    local_60 = 0x39;
    local_68 = 0x3139303939383838;
    local_70 = 0x3738363835383438;
    local_78 = 0x3338323831383038;
    local_80 = 0x3937383737373637;
    local_88 = 0x3537343733373237;
    local_90 = 0x3137303739363836;
    local_98 = 0x3736363635363436;
    local_a0 = 0x3336323631363036;
    local_a8 = 0x3935383537353635;
    local_b0 = 0x3535343533353235;
    local_b8 = 0x3135303539343834;
    local_c0 = 0x3734363435343434;
    local_c8 = 0x3334323431343034;
    local_d0 = 0x3933383337333633;
    local_d8 = 0x3533343333333233;
    local_e0 = 0x3133303339323832;
    local_e8 = 0x3732363235323432;
    local_f0 = 0x3332323231323032;
    local_f8 = 0x3931383137313631;
    local_100 = 0x3531343133313231;
    uStack_108 = (longlong *)0x3131303139303830;
    local_110 = (longlong *)0x3730363035303430;
    local_118 = (longlong **)0x3330323031303030;
    pcVar25[1] = *(char *)((longlong)&local_118 + (ulonglong)(new_item_x * 2 + 1));
    cVar26 = *(char *)((longlong)&local_118 + (ulonglong)(new_item_x * 2));
  }
  *pcVar25 = cVar26;
  plVar9 = (longlong *)
           std::__cxx11::basic_string<>::_M_replace_aux
                     ((basic_string<> *)&local_158,local_150,0,1,'\n');
  pplVar12 = (longlong **)(plVar9 + 2);
  if ((longlong **)*plVar9 == pplVar12) {
    uVar21 = plVar9[1] + 1;
    pplVar18 = pplVar12;
    pplVar10 = local_128;
    if (7 < (uint)uVar21) {
      uVar15 = 0;
      do {
        new_item_x = (int)uVar15 + 8;
        uVar16 = (ulonglong)new_item_x;
        *(undefined8 *)((longlong)local_128 + uVar15) = *(undefined8 *)((longlong)pplVar12 + uVar 15)
        ;
        uVar15 = uVar16;
      } while (new_item_x < ((uint)uVar21 & 0xfffffff8));
      pplVar10 = (longlong **)((longlong)local_128 + uVar16);
      pplVar18 = (longlong **)(uVar16 + (longlong)pplVar12);
    }
    lVar13 = 0;
    if ((uVar21 & 4) != 0) {
      *(undefined4 *)pplVar10 = *(undefined4 *)pplVar18;
      lVar13 = 4;
    }
    if ((uVar21 & 2) != 0) {
      *(undefined2 *)((longlong)pplVar10 + lVar13) = *(undefined2 *)((longlong)pplVar18 + lVar13 );
      lVar13 = lVar13 + 2;
    }
    local_138 = local_128;
    if ((uVar21 & 1) != 0) {
      *(undefined *)((longlong)pplVar10 + lVar13) = *(undefined *)((longlong)pplVar18 + lVar13);
    }
  }
  else {
    local_128[0] = (longlong *)plVar9[2];
    local_138 = (longlong **)*plVar9;
  }
  local_130 = plVar9[1];
  *(undefined *)(plVar9 + 2) = 0;
  plVar9[1] = 0;
  uVar21 = *(ulonglong *)(param_1 + 8);
  *plVar9 = (longlong)pplVar12;
  if (0x3fffffffffffffff - local_130 < uVar21) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("basic_string::append");
  }
  pplVar10 = (longlong **)
             std::__cxx11::basic_string<>::_M_append
                       ((basic_string<> *)&local_138,*(char **)param_1,uVar21);
  pplVar12 = pplVar10 + 2;
  local_118 = (longlong **)&uStack_108;
  if ((longlong **)*pplVar10 == pplVar12) {
    uVar21 = (longlong)pplVar10[1] + 1;
    pplVar17 = pplVar12;
    pplVar18 = (longlong **)&uStack_108;
    if (7 < (uint)uVar21) {
      uVar15 = 0;
      do {
        new_item_x = (int)uVar15 + 8;
        uVar16 = (ulonglong)new_item_x;
        *(undefined8 *)((longlong)&uStack_108 + uVar15) =
             *(undefined8 *)((longlong)pplVar12 + uVar15);
        uVar15 = uVar16;
      } while (new_item_x < ((uint)uVar21 & 0xfffffff8));
      pplVar18 = (longlong **)((longlong)&uStack_108 + uVar16);
      pplVar17 = (longlong **)(uVar16 + (longlong)pplVar12);
    }
    lVar13 = 0;
    if ((uVar21 & 4) != 0) {
      *(undefined4 *)pplVar18 = *(undefined4 *)pplVar17;
      lVar13 = 4;
    }
    if ((uVar21 & 2) != 0) {
      *(undefined2 *)((longlong)pplVar18 + lVar13) = *(undefined2 *)((longlong)pplVar17 + lVar13 );
      lVar13 = lVar13 + 2;
    }
    if ((uVar21 & 1) != 0) {
      *(undefined *)((longlong)pplVar18 + lVar13) = *(undefined *)((longlong)pplVar17 + lVar13);
    }
  }
  else {
    local_118 = (longlong **)*pplVar10;
    uStack_108 = pplVar10[2];
  }
  plVar9 = pplVar10[1];
  local_110 = plVar9;
  *pplVar10 = (longlong *)pplVar12;
  *(undefined *)(pplVar10 + 2) = 0;
  pplVar10[1] = (longlong *)0x0;
  pplVar12 = *(longlong ***)param_1;
  local_110._0_4_ = (uint)plVar9;
  local_110._4_4_ = (undefined4)((ulonglong)plVar9 >> 0x20);
  uVar1 = (undefined4)uStack_108;
  if (local_180 == pplVar12) {
    if (local_118 != (longlong **)&uStack_108) {
      *(longlong ***)param_1 = local_118;
      *(uint *)(param_1 + 8) = (uint)local_110;
      *(undefined4 *)(param_1 + 0xc) = local_110._4_4_;
      *(undefined4 *)(param_1 + 0x10) = (undefined4)uStack_108;
      *(undefined4 *)(param_1 + 0x14) = uStack_108._4_4_;
      local_118 = (longlong **)&uStack_108;
      goto LAB_140159732;
    }
  }
  else if (local_118 != (longlong **)&uStack_108) {
    plVar9 = *(longlong **)(param_1 + 0x10);
    *(longlong ***)param_1 = local_118;
    *(uint *)(param_1 + 8) = (uint)local_110;
    *(undefined4 *)(param_1 + 0xc) = local_110._4_4_;
    *(undefined4 *)(param_1 + 0x10) = (undefined4)uStack_108;
    *(undefined4 *)(param_1 + 0x14) = uStack_108._4_4_;
    local_118 = (longlong **)&uStack_108;
    if (pplVar12 != (longlong **)0x0) {
      local_118 = pplVar12;
      uStack_108 = plVar9;
    }
    goto LAB_140159732;
  }
  if (plVar9 != (longlong *)0x0) {
    if (plVar9 == (longlong *)0x1) {
      *(undefined *)pplVar12 = (undefined)uStack_108;
      pplVar12 = *(longlong ***)param_1;
    }
    else {
      uVar21 = (ulonglong)plVar9 & 0xffffffff;
      if ((uint)local_110 < 8) {
        if (((ulonglong)plVar9 & 4) == 0) {
          if ((uint)local_110 != 0) {
            *(undefined *)pplVar12 = (undefined)uStack_108;
            if (((ulonglong)plVar9 & 2) == 0) goto LAB_14015ba3d;
            *(undefined2 *)((longlong)pplVar12 + (uVar21 - 2)) =
                 *(undefined2 *)((longlong)&local_110 + uVar21 + 6);
            pplVar12 = *(longlong ***)param_1;
          }
        }
        else {
          *(undefined4 *)pplVar12 = uVar1;
          *(undefined4 *)((longlong)pplVar12 + (uVar21 - 4)) =
               *(undefined4 *)((longlong)&local_110 + uVar21 + 4);
          pplVar12 = *(longlong ***)param_1;
        }
      }
      else {
        *pplVar12 = uStack_108;
        *(undefined8 *)((longlong)pplVar12 + (((ulonglong)plVar9 & 0xffffffff) - 8)) =
             *(undefined8 *)((longlong)&local_110 + ((ulonglong)plVar9 & 0xffffffff));
        lVar13 = (longlong)pplVar12 - ((ulonglong)(pplVar12 + 1) & 0xfffffffffffffff8);
        new_item_x = (int)lVar13 + (uint)local_110 & 0xfffffff8;
        if (7 < new_item_x) {
          uVar21 = 0;
          do {
            new_item_y = (int)uVar21 + 8;
            *(undefined8 *)(((ulonglong)(pplVar12 + 1) & 0xfffffffffffffff8) + uVar21) =
                 *(undefined8 *)((longlong)&uStack_108 + (uVar21 - lVar13));
            uVar21 = (ulonglong)new_item_y;
          } while (new_item_y < new_item_x);
        }
LAB_14015ba3d:
        pplVar12 = *(longlong ***)param_1;
      }
    }
  }
  *(longlong **)(param_1 + 8) = plVar9;
  *(undefined *)((longlong)pplVar12 + (longlong)plVar9) = 0;
LAB_140159732:
  local_110 = (longlong *)0x0;
  *(undefined *)local_118 = 0;
  if (local_118 != (longlong **)&uStack_108) {
    operator.delete(local_118,(longlong)uStack_108 + 1);
  }
  if (local_138 != local_128) {
    operator.delete(local_138,(longlong)local_128[0] + 1);
  }
  if (local_158 != local_148) {
    operator.delete(local_158,local_148[0] + 1);
  }
  return param_1;
}

