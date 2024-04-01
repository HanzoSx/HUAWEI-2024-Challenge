
/* World::World(_iobuf*, int, char**, std::__cxx11::basic_string<char, std::char_traits<char>,
   std::allocator<char> >, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>,
   std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>,
   std::allocator<char> > > >) */

void __thiscall
World::World(void *this,undefined8 param_2,int param_3,longlong param_4,undefined8 *param_11,
            longlong *param_12)

{
  longlong **pplVar1;
  char *pcVar2;
  undefined *_Src;
  Player *pPVar3;
  int iVar4;
  undefined8 *this_00;
  size_t sVar5;
  longlong *plVar6;
  void *_Dst;
  uint uVar7;
  longlong lVar8;
  ulonglong uVar9;
  longlong **pplVar11;
  Player *this_01;
  undefined8 *puVar12;
  int iVar13;
  ulonglong uVar14;
  longlong lVar15;
  longlong **pplVar16;
  bool bVar17;
  longlong **local_98;
  longlong local_90;
  longlong *local_88 [2];
  _iobuf local_78;
  ulonglong uVar10;
  
  uVar14 = (ulonglong)(param_3 - optind);
  if (0x572620ae4c415c < uVar14) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("cannot create std::vector larger than max_size()");
  }
  *(undefined8 *)((longlong)this + 0x57f20) = 0;
  *(undefined (*) [16])((longlong)this + 0x57f10) = (undefined  [16])0x0;
  if (uVar14 == 0) {
    *(undefined8 *)((longlong)this + 0x57f10) = 0;
    puVar12 = (undefined8 *)0x0;
    *(undefined8 *)((longlong)this + 0x57f20) = 0;
  }
  else {
    this_00 = (undefined8 *)operator.new(uVar14 * 0x178);
    *(undefined8 **)((longlong)this + 0x57f20) = this_00 + uVar14 * 0x2f;
    *(undefined8 **)((longlong)this + 0x57f10) = this_00;
    *(undefined8 **)((longlong)this + 0x57f18) = this_00;
    do {
      puVar12 = this_00;
      for (lVar8 = 0x2f; lVar8 != 0; lVar8 = lVar8 + -1) {
        *puVar12 = 0;
        puVar12 = puVar12 + 1;
      }
      ProcessIO::ProcessIO((ProcessIO *)this_00,true,true,true);
      *this_00 = &PTR_~Player_1402c5590;
      *(undefined4 *)(this_00 + 0xe) = 0;
      *(undefined (*) [16])(this_00 + 0xf) = (undefined  [16])0x0;
      *(undefined (*) [16])(this_00 + 0x11) = (undefined  [16])0x0;
      *(undefined (*) [16])(this_00 + 0x13) = (undefined  [16])0x0;
      *(undefined (*) [16])(this_00 + 0x15) = (undefined  [16])0x0;
      *(undefined (*) [16])(this_00 + 0x17) = (undefined  [16])0x0;
      *(undefined (*) [16])(this_00 + 0x19) = (undefined  [16])0x0;
      pthread_mutex_init(this_00 + 0x1b);
      this_00[0x1d] = 0;
      this_00[0x1c] = this_00 + 0x1e;
      this_00[0x27] = this_00 + 0x29;
      puVar12 = this_00 + 0x2f;
      *(undefined *)(this_00 + 0x1e) = 0;
      *(undefined (*) [16])(this_00 + 0x21) = (undefined  [16])0x0;
      *(undefined (*) [16])(this_00 + 0x23) = (undefined  [16])0x0;
      *(undefined (*) [16])(this_00 + 0x25) = (undefined  [16])0x0;
      this_00[0x28] = 0;
      *(undefined *)(this_00 + 0x29) = 0;
      this_00[0x2b] = this_00 + 0x2d;
      this_00[0x2c] = 0;
      *(undefined *)(this_00 + 0x2d) = 0;
      uVar14 = uVar14 - 1;
      this_00 = puVar12;
    } while (uVar14 != 0);
  }
  *(undefined8 **)((longlong)this + 0x57f18) = puVar12;
  *(undefined (*) [16])((longlong)this + 0x57f28) = (undefined  [16])0x0;
  *(undefined8 *)((longlong)this + 0x57f98) = 0;
  *(undefined (*) [16])((longlong)this + 0x57f38) = (undefined  [16])0x0;
  *(undefined (*) [16])((longlong)this + 0x57f48) = (undefined  [16])0x0;
  *(undefined (*) [16])((longlong)this + 0x57f58) = (undefined  [16])0x0;
  *(undefined (*) [16])((longlong)this + 0x57f68) = (undefined  [16])0x0;
  *(undefined (*) [16])((longlong)this + 0x57f78) = (undefined  [16])0x0;
  *(undefined (*) [16])((longlong)this + 0x57f88) = (undefined  [16])0x0;
  replay_protocol::Rep::Rep((Rep *)((longlong)this + 0x57fa0),(Arena *)0x0,false);
  *(undefined *)((longlong)this + 0x58030) = 0;
  _Dst = (void *)((longlong)this + 0x58050);
  *(longlong *)((longlong)this + 0x58020) = (longlong)this + 0x58030;
  *(undefined8 *)((longlong)this + 0x58028) = 0;
  pcVar2 = (char *)param_11[1];
  *(void **)((longlong)this + 0x58040) = _Dst;
  _Src = (undefined *)*param_11;
  local_78._ptr = pcVar2;
  if (pcVar2 < (char *)0x10) {
    if (pcVar2 == (char *)0x1) {
      *(undefined *)((longlong)this + 0x58050) = *_Src;
      goto LAB_1401577bb;
    }
    if (pcVar2 == (char *)0x0) goto LAB_1401577bb;
  }
  else {
    _Dst = (void *)std::__cxx11::basic_string<>::_M_create
                             ((basic_string<> *)((longlong)this + 0x58040),(ulonglong *)&local_78 ,0)
    ;
    *(void **)((longlong)this + 0x58040) = _Dst;
    *(char **)((longlong)this + 0x58050) = local_78._ptr;
  }
  memcpy(_Dst,_Src,(size_t)pcVar2);
  _Dst = *(void **)((longlong)this + 0x58040);
LAB_1401577bb:
  *(char **)((longlong)this + 0x58048) = local_78._ptr;
  lVar15 = 0;
  *(char *)((longlong)_Dst + (longlong)local_78._ptr) = '\0';
  uVar14 = 0;
  lVar8 = *param_12;
  if (lVar8 != param_12[1]) {
    do {
      pcVar2 = *(char **)(lVar8 + uVar14 * 0x20);
      lVar8 = *(longlong *)((longlong)this + 0x57f10) + lVar15;
      sVar5 = strlen(pcVar2);
      std::__cxx11::basic_string<>::_M_replace
                ((basic_string<> *)(lVar8 + 0x38),0,*(ulonglong *)(lVar8 + 0x40),pcVar2,sVar5);
      lVar8 = *param_12;
      uVar14 = uVar14 + 1;
      lVar15 = lVar15 + 0x178;
    } while (uVar14 < (ulonglong)(param_12[1] - lVar8 >> 5));
  }
  lVar8 = 0;
  iVar13 = 0;
  iVar4 = optind;
  while (iVar4 < param_3) {
    ProcessIO::Start((ProcessIO *)(*(longlong *)((longlong)this + 0x57f10) + lVar8),
                     *(char **)(param_4 + (longlong)iVar4 * 8));
    iVar13 = iVar13 + 1;
    lVar8 = lVar8 + 0x178;
    iVar4 = optind + iVar13;
  }
  *(undefined4 *)this = 0;
  memset((void *)((longlong)this + 0x9d10),0,160000);
  memset((void *)((longlong)this + 0x30e10),0,160000);
  input_map[abi:cxx11](&local_78);
  if (0x3fffffffffffffff - local_78._8_8_ < 3) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("basic_string::append");
  }
  plVar6 = (longlong *)std::__cxx11::basic_string<>::_M_append((basic_string<> *)&local_78,"OK\n ",3)
  ;
  pplVar1 = (longlong **)(plVar6 + 2);
  local_90 = plVar6[1];
  if ((longlong **)*plVar6 == pplVar1) {
    uVar14 = local_90 + 1;
    pplVar11 = pplVar1;
    pplVar16 = local_88;
    if (7 < (uint)uVar14) {
      uVar9 = 0;
      do {
        uVar7 = (int)uVar9 + 8;
        uVar10 = (ulonglong)uVar7;
        *(undefined8 *)((longlong)local_88 + uVar9) = *(undefined8 *)((longlong)pplVar1 + uVar9);
        uVar9 = uVar10;
      } while (uVar7 < ((uint)uVar14 & 0xfffffff8));
      pplVar16 = (longlong **)((longlong)local_88 + uVar10);
      pplVar11 = (longlong **)(uVar10 + (longlong)pplVar1);
    }
    lVar8 = 0;
    if ((uVar14 & 4) != 0) {
      *(undefined4 *)pplVar16 = *(undefined4 *)pplVar11;
      lVar8 = 4;
    }
    if ((uVar14 & 2) != 0) {
      *(undefined2 *)((longlong)pplVar16 + lVar8) = *(undefined2 *)((longlong)pplVar11 + lVar8);
      lVar8 = lVar8 + 2;
    }
    if ((uVar14 & 1) != 0) {
      *(undefined *)((longlong)pplVar16 + lVar8) = *(undefined *)((longlong)pplVar11 + lVar8);
    }
    local_90 = plVar6[1];
    local_98 = local_88;
  }
  else {
    local_88[0] = (longlong *)plVar6[2];
    local_98 = (longlong **)*plVar6;
  }
  *plVar6 = (longlong)pplVar1;
  *(undefined *)(plVar6 + 2) = 0;
  plVar6[1] = 0;
  if ((char **)local_78._ptr != &local_78._base) {
    operator.delete(local_78._ptr,(ulonglong)(local_78._base + 1));
  }
  pPVar3 = *(Player **)((longlong)this + 0x57f18);
  for (this_01 = *(Player **)((longlong)this + 0x57f10); pPVar3 != this_01;
      this_01 = this_01 + 0x178) {
    std::__cxx11::basic_string<>::_M_assign
              ((basic_string<> *)(this_01 + 0xe0),(basic_string *)&local_98);
    Player::flush_write_buffer(this_01,(basic_string *)(basic_string<> *)((longlong)this + 0x580 40))
    ;
  }
  wait_player_output((World *)this,5000);
  lVar15 = *(longlong *)((longlong)this + 0x57f18);
  for (lVar8 = *(longlong *)((longlong)this + 0x57f10); lVar15 != lVar8; lVar8 = lVar8 + 0x178) {
    bVar17 = *(int *)(lVar8 + 0x70) != 2;
    *(uint *)(lVar8 + 0x70) = bVar17 + 3 + (uint)bVar17;
  }
  if (local_98 != local_88) {
    operator.delete(local_98,(longlong)local_88[0] + 1);
  }
  return;
}

