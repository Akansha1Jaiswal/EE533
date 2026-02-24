/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                         */
/*  \   \        Copyright (c) 2003-2007 Xilinx, Inc.                 */
/*  /   /        All Right Reserved.                                  */
/* /---/   /\                                                         */
/* \   \  /  \                                                        */
/*  \___\/\___\                                                       */
/**********************************************************************/

/* This file is designed for use with ISim build 0x734844ce */

#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Documents and Settings/student/My Documents/Lab/MT_pipe/pipeineMT_tb.v";
static int ng1[] = {0, 0};
static int ng2[] = {4, 0};
static int ng3[] = {16, 0};
static unsigned int ng4[] = {3735928559U, 0U};
static unsigned int ng5[] = {0U, 0U};
static int ng6[] = {1, 0};
static const char *ng7 = "  PASS | %s | T%0d R%02d = 0x%08h (%0d) [direct read]";
static const char *ng8 = "  FAIL | %s | T%0d R%02d NEVER WRITTEN | direct=%08h | exp=%0d";
static const char *ng9 = "  PASS | %s | T%0d R%02d = 0x%08h (%0d)";
static const char *ng10 = "  FAIL | %s | T%0d R%02d = 0x%08h (%0d) | exp=0x%08h (%0d)";
static const char *ng11 = "=== BRAM DIAGNOSTIC (cycle %0d) ===";
static const char *ng12 = "  current_thread  = %0d";
static const char *ng13 = "  pc[0]           = %0d (expect   0)";
static const char *ng14 = "  pc[1]           = %0d (expect  64)";
static const char *ng15 = "  pc[2]           = %0d (expect 128)";
static int ng16[] = {2, 0};
static const char *ng17 = "  pc[3]           = %0d (expect 192)";
static int ng18[] = {3, 0};
static const char *ng19 = "  pc_out          = %0d";
static const char *ng20 = "  instruction_IF  = %08h";
static unsigned int ng21[] = {0U, 4294967295U};
static const char *ng22 = "  STATUS: FATAL ZZZ -- IMem ena=0 or not driven";
static unsigned int ng23[] = {4294967295U, 4294967295U};
static const char *ng24 = "  STATUS: FATAL XXX -- BRAM uninitialized";
static const char *ng25 = "  STATUS: FATAL 000 -- .coe not loaded";
static unsigned int ng26[] = {3785359360U, 0U};
static const char *ng27 = "  STATUS: WARN NOP  -- wrong PC or empty region";
static const char *ng28 = "  STATUS: OK %08h -- BRAM responding correctly";
static unsigned int ng29[] = {1U, 0U};
static const char *ng30 = "[%04d] CAPTURE: T%0d R%02d <= 0x%08h (%0d)";
static int ng31[] = {80, 0};
static const char *ng32 = "[%04d] IF: T%0d PC=%03d instr=%08h | ID: T%0d | EX: T%0d | WB: T%0d";
static const char *ng33 = "[%04d] WB_RAW: T%0d R%02d <= %08h (%0d)";
static const char *ng34 = "[%04d] STALL: T%0d waiting on R%0d";
static const char *ng35 = "[%04d] FWD: T%0d fwdA=%02b fwdB=%02b";
static const char *ng36 = "[%04d] BRANCH: T%0d -> word=%0d (0x%08h)";
static const char *ng37 = "[%04d] STR: T%0d mem[byte=0x%04h word=%0d] <= 0x%08h (%0d)";
static const char *ng38 = "[%04d] LDR: T%0d from mem[byte=0x%04h]";
static const char *ng39 = "[%04d] CPSR: T%0d N=%b Z=%b C=%b V=%b";
static const char *ng40 = "tb_fourprog.vcd";
static int ng41[] = {10, 0};
static const char *ng42 = "";
static const char *ng43 = "************************************************************";
static const char *ng44 = "  4-Thread Pipeline: 4 Independent Programs";
static const char *ng45 = "  T0=Fibonacci  T1=ArraySum  T2=LinearSearch  T3=MaxFinder";
static const char *ng46 = "=== PC START ADDRESS CHECK ===";
static const char *ng47 = "  T0 PC = %0d %s";
static int ng48[] = {1095979817, 0, 10320, 0, 0, 0, 0, 0, 0, 0};
static int ng49[] = {1679831081, 0, 1701016677, 0, 543520880, 0, 1229725741, 0, 2639425, 0};
static const char *ng50 = "  T1 PC = %0d %s";
static int ng51[] = {64, 0};
static int ng52[] = {540423209, 0, 1668572516, 0, 1702391909, 0, 1277177120, 0, 675692873, 0};
static const char *ng53 = "  T2 PC = %0d %s";
static int ng54[] = {128, 0};
static int ng55[] = {1095979817, 0, 10320, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static int ng56[] = {825374761, 0, 1952801824, 0, 2020631907, 0, 539828325, 0, 1178683724, 0, 40, 0};
static const char *ng57 = "  T3 PC = %0d %s";
static int ng58[] = {192, 0};
static int ng59[] = {825831977, 0, 1952801824, 0, 2020631907, 0, 539828325, 0, 1178683724, 0, 40, 0};
static int ng60[] = {5, 0};
static int ng61[] = {5000, 0};
static const char *ng62 = "=== FINAL CPSR STATE ===";
static const char *ng63 = "  T0: N=%b Z=%b C=%b V=%b";
static const char *ng64 = "  T1: N=%b Z=%b C=%b V=%b";
static const char *ng65 = "  T2: N=%b Z=%b C=%b V=%b";
static const char *ng66 = "  T3: N=%b Z=%b C=%b V=%b";
static const char *ng67 = "=== PROGRAM RESULTS ===";
static const char *ng68 = "--- T0: Fibonacci (expect R2=34) ---";
static unsigned int ng69[] = {2U, 0U};
static unsigned int ng70[] = {34U, 0U};
static int ng71[] = {4606274, 0, 0, 0, 0, 0};
static const char *ng72 = "--- T1: Array Sum (expect R0=360) ---";
static unsigned int ng73[] = {360U, 0U};
static int ng74[] = {5461325, 0, 0, 0, 0, 0};
static const char *ng75 = "--- T2: Linear Search (expect R0=2) ---";
static int ng76[] = {5460547, 0, 0, 0, 0, 0};
static const char *ng77 = "--- T3: Max Finder (expect R0=95) ---";
static unsigned int ng78[] = {3U, 0U};
static unsigned int ng79[] = {95U, 0U};
static int ng80[] = {5063000, 0, 0, 0, 0, 0};
static const char *ng81 = "=== THREAD ISOLATION CHECK ===";
static const char *ng82 = "  PASS: T1 R2 != T0 R2 (no cross-thread contamination)";
static const char *ng83 = "  FAIL: T1 R2 == T0 R2 -- possible cross-thread write";
static const char *ng84 = "  T0 wrote R2: %s";
static int ng85[] = {5850451, 0};
static int ng86[] = {20047, 0};
static const char *ng87 = "  T1 wrote R0: %s";
static const char *ng88 = "  T2 wrote R0: %s";
static const char *ng89 = "  T3 wrote R0: %s";
static const char *ng90 = "=== FINAL SHADOW REGISTER FILE ===";
static const char *ng91 = "  Thread %0d:";
static const char *ng92 = "    R%02d = 0x%08h (%0d)";
static const char *ng93 = "    R%02d = <never written>";
static const char *ng94 = "=== DIRECT REGFILE READ (backup) ===";
static const char *ng95 = "  T0 R2 = 0x%08h (%0d) -- expect 34";
static const char *ng96 = "  T1 R0 = 0x%08h (%0d) -- expect 360";
static unsigned int ng97[] = {16U, 0U};
static const char *ng98 = "  T2 R0 = 0x%08h (%0d) -- expect 2";
static unsigned int ng99[] = {32U, 0U};
static const char *ng100 = "  T3 R0 = 0x%08h (%0d) -- expect 95";
static unsigned int ng101[] = {48U, 0U};
static const char *ng102 = "  FINAL SUMMARY: %0d PASSED  %0d FAILED";
static const char *ng103 = "  *** ALL TESTS PASSED ***";
static const char *ng104 = "  *** FAILURES DETECTED -- check waveform ***";



static int sp_clear_shadow(char *t1, char *t2)
{
    char t7[8];
    char t16[8];
    char t17[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    unsigned int t31;
    int t32;
    char *t33;
    unsigned int t34;
    int t35;
    int t36;
    unsigned int t37;
    unsigned int t38;
    int t39;
    int t40;

LAB0:    t0 = 1;
    t3 = (t1 + 456);
    xsi_vlog_subprogram_setdisablestate(t3, &&LAB2);
    xsi_set_current_line(37, ng0);

LAB3:    xsi_set_current_line(38, ng0);
    xsi_set_current_line(38, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t1 + 1880);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB4:    t3 = (t1 + 1880);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng2)));
    memset(t7, 0, 8);
    xsi_vlog_signed_less(t7, 32, t5, 32, t6, 32);
    t8 = (t7 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB5;

LAB6:
LAB2:    xsi_vlog_dispose_subprogram_invocation(t2);
    t0 = 0;

LAB1:    return t0;
LAB5:    xsi_set_current_line(39, ng0);
    xsi_set_current_line(39, ng0);
    t14 = ((char*)((ng1)));
    t15 = (t1 + 1972);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 32);

LAB7:    t3 = (t1 + 1972);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng3)));
    memset(t7, 0, 8);
    xsi_vlog_signed_less(t7, 32, t5, 32, t6, 32);
    t8 = (t7 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB8;

LAB9:    xsi_set_current_line(38, ng0);
    t3 = (t1 + 1880);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 1880);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    goto LAB4;

LAB8:    xsi_set_current_line(39, ng0);

LAB10:    xsi_set_current_line(40, ng0);
    t14 = ((char*)((ng4)));
    t15 = (t1 + 1696);
    t18 = (t1 + 1696);
    t19 = (t18 + 40U);
    t20 = *((char **)t19);
    t21 = (t1 + 1696);
    t22 = (t21 + 36U);
    t23 = *((char **)t22);
    t24 = (t1 + 1880);
    t25 = (t24 + 32U);
    t26 = *((char **)t25);
    t27 = (t1 + 1972);
    t28 = (t27 + 32U);
    t29 = *((char **)t28);
    xsi_vlog_generic_convert_array_indices(t16, t17, t20, t23, 2, 2, t26, 32, 1, t29, 32, 1);
    t30 = (t16 + 4U);
    t31 = *((unsigned int *)t30);
    t32 = (!(t31));
    t33 = (t17 + 4U);
    t34 = *((unsigned int *)t33);
    t35 = (!(t34));
    t36 = (t32 && t35);
    if (t36 == 1)
        goto LAB11;

LAB12:    xsi_set_current_line(41, ng0);
    t3 = ((char*)((ng5)));
    t4 = (t1 + 1788);
    t5 = (t1 + 1788);
    t6 = (t5 + 40U);
    t8 = *((char **)t6);
    t14 = (t1 + 1788);
    t15 = (t14 + 36U);
    t18 = *((char **)t15);
    t19 = (t1 + 1880);
    t20 = (t19 + 32U);
    t21 = *((char **)t20);
    t22 = (t1 + 1972);
    t23 = (t22 + 32U);
    t24 = *((char **)t23);
    xsi_vlog_generic_convert_array_indices(t7, t16, t8, t18, 2, 2, t21, 32, 1, t24, 32, 1);
    t25 = (t7 + 4U);
    t9 = *((unsigned int *)t25);
    t32 = (!(t9));
    t26 = (t16 + 4U);
    t10 = *((unsigned int *)t26);
    t35 = (!(t10));
    t36 = (t32 && t35);
    if (t36 == 1)
        goto LAB13;

LAB14:    xsi_set_current_line(39, ng0);
    t3 = (t1 + 1972);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 1972);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    goto LAB7;

LAB11:    t37 = *((unsigned int *)t16);
    t38 = *((unsigned int *)t17);
    t39 = (t37 - t38);
    t40 = (t39 + 1);
    xsi_vlogvar_assign_value(t15, t14, 0, *((unsigned int *)t17), t40);
    goto LAB12;

LAB13:    t11 = *((unsigned int *)t7);
    t12 = *((unsigned int *)t16);
    t39 = (t11 - t12);
    t40 = (t39 + 1);
    xsi_vlogvar_assign_value(t4, t3, 0, *((unsigned int *)t16), t40);
    goto LAB14;

}

static int sp_check_reg(char *t1, char *t2)
{
    char t7[8];
    char t21[8];
    char t37[8];
    char t46[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t47;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;

LAB0:    t0 = 1;
    t3 = (t1 + 696);
    xsi_vlog_subprogram_setdisablestate(t3, &&LAB2);
    xsi_set_current_line(99, ng0);

LAB3:    xsi_set_current_line(101, ng0);
    t4 = (t1 + 1696);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t8 = (t1 + 1696);
    t9 = (t8 + 40U);
    t10 = *((char **)t9);
    t11 = (t1 + 1696);
    t12 = (t11 + 36U);
    t13 = *((char **)t12);
    t14 = (t1 + 2616);
    t15 = (t14 + 32U);
    t16 = *((char **)t15);
    t17 = (t1 + 2708);
    t18 = (t17 + 32U);
    t19 = *((char **)t18);
    xsi_vlog_generic_get_array_select_value(t7, 32, t6, t10, t13, 2, 2, t16, 2, 2, t19, 4, 2);
    t20 = (t1 + 2984);
    xsi_vlogvar_assign_value(t20, t7, 0, 0, 32);
    xsi_set_current_line(102, ng0);
    t3 = (t1 + 1788);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t1 + 1788);
    t8 = (t6 + 40U);
    t9 = *((char **)t8);
    t10 = (t1 + 1788);
    t11 = (t10 + 36U);
    t12 = *((char **)t11);
    t13 = (t1 + 2616);
    t14 = (t13 + 32U);
    t15 = *((char **)t14);
    t16 = (t1 + 2708);
    t17 = (t16 + 32U);
    t18 = *((char **)t17);
    xsi_vlog_generic_get_array_select_value(t21, 1, t5, t9, t12, 2, 2, t15, 2, 2, t18, 4, 2);
    memset(t7, 0, 8);
    t19 = (t7 + 4U);
    t20 = (t21 + 4U);
    t22 = *((unsigned int *)t20);
    t23 = (~(t22));
    t24 = *((unsigned int *)t21);
    t25 = (t24 & t23);
    t26 = (t25 & 1U);
    if (t26 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t20) == 0)
        goto LAB4;

LAB6:    *((unsigned int *)t7) = 1;
    *((unsigned int *)t19) = 1;

LAB7:    t27 = (t7 + 4U);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t7);
    t31 = (t30 & t29);
    t32 = (t31 != 0);
    if (t32 > 0)
        goto LAB8;

LAB9:    xsi_set_current_line(114, ng0);
    t3 = (t1 + 2984);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t1 + 2800);
    t8 = (t6 + 32U);
    t9 = *((char **)t8);
    memset(t7, 0, 8);
    t10 = (t5 + 4U);
    t11 = (t9 + 4U);
    if (*((unsigned int *)t5) != *((unsigned int *)t9))
        goto LAB22;

LAB20:    if (*((unsigned int *)t10) != *((unsigned int *)t11))
        goto LAB22;

LAB21:    *((unsigned int *)t7) = 1;

LAB22:    t12 = (t7 + 4U);
    t22 = *((unsigned int *)t12);
    t23 = (~(t22));
    t24 = *((unsigned int *)t7);
    t25 = (t24 & t23);
    t26 = (t25 != 0);
    if (t26 > 0)
        goto LAB23;

LAB24:    xsi_set_current_line(118, ng0);

LAB27:    xsi_set_current_line(119, ng0);
    t3 = (t1 + 2892);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t1 + 2616);
    t8 = (t6 + 32U);
    t9 = *((char **)t8);
    t10 = (t1 + 2708);
    t11 = (t10 + 32U);
    t12 = *((char **)t11);
    t13 = (t1 + 2984);
    t14 = (t13 + 32U);
    t15 = *((char **)t14);
    t16 = (t1 + 2984);
    t17 = (t16 + 32U);
    t18 = *((char **)t17);
    t19 = (t1 + 2800);
    t20 = (t19 + 32U);
    t27 = *((char **)t20);
    t33 = (t1 + 2800);
    t34 = (t33 + 32U);
    t35 = *((char **)t34);
    xsi_vlogfile_write(1, 0, ng10, 8, t1, (char)118, t5, 80, (char)118, t9, 2, (char)118, t12, 4, (char)118, t15, 32, (char)118, t18, 32, (char)118, t27, 32, (char)118, t35, 32);
    xsi_set_current_line(122, ng0);
    t3 = (t1 + 2524);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 2524);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);

LAB25:
LAB10:
LAB2:    xsi_vlog_dispose_subprogram_invocation(t2);
    t0 = 0;

LAB1:    return t0;
LAB4:    *((unsigned int *)t7) = 1;
    goto LAB7;

LAB8:    xsi_set_current_line(102, ng0);

LAB11:    xsi_set_current_line(104, ng0);
    t33 = (t1 + 8324);
    t34 = *((char **)t33);
    t35 = ((((char*)(t34))) + 32U);
    t36 = *((char **)t35);
    t38 = (t1 + 8344);
    t39 = *((char **)t38);
    t40 = ((((char*)(t39))) + 40U);
    t41 = *((char **)t40);
    t42 = (t1 + 8364);
    t43 = *((char **)t42);
    t44 = ((((char*)(t43))) + 36U);
    t45 = *((char **)t44);
    t47 = (t1 + 2708);
    t48 = (t47 + 32U);
    t49 = *((char **)t48);
    t50 = (t1 + 2616);
    t51 = (t50 + 32U);
    t52 = *((char **)t51);
    xsi_vlogtype_concat(t46, 6, 6, 2U, t52, 2, t49, 4);
    xsi_vlog_generic_get_array_select_value(t37, 32, t36, t41, t45, 2, 1, t46, 6, 2);
    t53 = (t1 + 2984);
    xsi_vlogvar_assign_value(t53, t37, 0, 0, 32);
    xsi_set_current_line(105, ng0);
    t3 = (t1 + 2984);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t1 + 2800);
    t8 = (t6 + 32U);
    t9 = *((char **)t8);
    memset(t7, 0, 8);
    t10 = (t5 + 4U);
    t11 = (t9 + 4U);
    if (*((unsigned int *)t5) != *((unsigned int *)t9))
        goto LAB14;

LAB12:    if (*((unsigned int *)t10) != *((unsigned int *)t11))
        goto LAB14;

LAB13:    *((unsigned int *)t7) = 1;

LAB14:    t12 = (t7 + 4U);
    t22 = *((unsigned int *)t12);
    t23 = (~(t22));
    t24 = *((unsigned int *)t7);
    t25 = (t24 & t23);
    t26 = (t25 != 0);
    if (t26 > 0)
        goto LAB15;

LAB16:    xsi_set_current_line(109, ng0);

LAB19:    xsi_set_current_line(110, ng0);
    t3 = (t1 + 2892);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t1 + 2616);
    t8 = (t6 + 32U);
    t9 = *((char **)t8);
    t10 = (t1 + 2708);
    t11 = (t10 + 32U);
    t12 = *((char **)t11);
    t13 = (t1 + 2984);
    t14 = (t13 + 32U);
    t15 = *((char **)t14);
    t16 = (t1 + 2800);
    t17 = (t16 + 32U);
    t18 = *((char **)t17);
    xsi_vlogfile_write(1, 0, ng8, 6, t1, (char)118, t5, 80, (char)118, t9, 2, (char)118, t12, 4, (char)118, t15, 32, (char)118, t18, 32);
    xsi_set_current_line(112, ng0);
    t3 = (t1 + 2524);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 2524);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);

LAB17:    goto LAB10;

LAB15:    xsi_set_current_line(105, ng0);

LAB18:    xsi_set_current_line(106, ng0);
    t13 = (t1 + 2892);
    t14 = (t13 + 32U);
    t15 = *((char **)t14);
    t16 = (t1 + 2616);
    t17 = (t16 + 32U);
    t18 = *((char **)t17);
    t19 = (t1 + 2708);
    t20 = (t19 + 32U);
    t27 = *((char **)t20);
    t33 = (t1 + 2984);
    t34 = (t33 + 32U);
    t35 = *((char **)t34);
    t36 = (t1 + 2984);
    t38 = (t36 + 32U);
    t39 = *((char **)t38);
    xsi_vlogfile_write(1, 0, ng7, 6, t1, (char)118, t15, 80, (char)118, t18, 2, (char)118, t27, 4, (char)118, t35, 32, (char)118, t39, 32);
    xsi_set_current_line(108, ng0);
    t3 = (t1 + 2432);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 2432);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    goto LAB17;

LAB23:    xsi_set_current_line(114, ng0);

LAB26:    xsi_set_current_line(115, ng0);
    t13 = (t1 + 2892);
    t14 = (t13 + 32U);
    t15 = *((char **)t14);
    t16 = (t1 + 2616);
    t17 = (t16 + 32U);
    t18 = *((char **)t17);
    t19 = (t1 + 2708);
    t20 = (t19 + 32U);
    t27 = *((char **)t20);
    t33 = (t1 + 2984);
    t34 = (t33 + 32U);
    t35 = *((char **)t34);
    t36 = (t1 + 2984);
    t38 = (t36 + 32U);
    t39 = *((char **)t38);
    xsi_vlogfile_write(1, 0, ng9, 6, t1, (char)118, t15, 80, (char)118, t18, 2, (char)118, t27, 4, (char)118, t35, 32, (char)118, t39, 32);
    xsi_set_current_line(117, ng0);
    t3 = (t1 + 2432);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 2432);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    goto LAB25;

}

static int sp_bram_diagnostic(char *t1, char *t2)
{
    char t7[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;

LAB0:    t0 = 1;
    t3 = (t1 + 936);
    xsi_vlog_subprogram_setdisablestate(t3, &&LAB2);
    xsi_set_current_line(131, ng0);

LAB3:    xsi_set_current_line(132, ng0);
    t4 = (t1 + 1604);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    xsi_vlogfile_write(1, 0, ng11, 2, t1, (char)119, t6, 32);
    xsi_set_current_line(133, ng0);
    t3 = (t1 + 8388);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 32U);
    t6 = *((char **)t5);
    xsi_vlogfile_write(1, 0, ng12, 2, t1, (char)118, t6, 2);
    xsi_set_current_line(134, ng0);
    t3 = (t1 + 8400);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 32U);
    t6 = *((char **)t5);
    t8 = (t1 + 8412);
    t9 = *((char **)t8);
    t10 = ((((char*)(t9))) + 40U);
    t11 = *((char **)t10);
    t12 = (t1 + 8424);
    t13 = *((char **)t12);
    t14 = ((((char*)(t13))) + 36U);
    t15 = *((char **)t14);
    t16 = ((char*)((ng1)));
    xsi_vlog_generic_get_array_select_value(t7, 32, t6, t11, t15, 2, 1, t16, 32, 1);
    xsi_vlogfile_write(1, 0, ng13, 2, t1, (char)118, t7, 32);
    xsi_set_current_line(135, ng0);
    t3 = (t1 + 8436);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 32U);
    t6 = *((char **)t5);
    t8 = (t1 + 8448);
    t9 = *((char **)t8);
    t10 = ((((char*)(t9))) + 40U);
    t11 = *((char **)t10);
    t12 = (t1 + 8460);
    t13 = *((char **)t12);
    t14 = ((((char*)(t13))) + 36U);
    t15 = *((char **)t14);
    t16 = ((char*)((ng6)));
    xsi_vlog_generic_get_array_select_value(t7, 32, t6, t11, t15, 2, 1, t16, 32, 1);
    xsi_vlogfile_write(1, 0, ng14, 2, t1, (char)118, t7, 32);
    xsi_set_current_line(136, ng0);
    t3 = (t1 + 8472);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 32U);
    t6 = *((char **)t5);
    t8 = (t1 + 8484);
    t9 = *((char **)t8);
    t10 = ((((char*)(t9))) + 40U);
    t11 = *((char **)t10);
    t12 = (t1 + 8496);
    t13 = *((char **)t12);
    t14 = ((((char*)(t13))) + 36U);
    t15 = *((char **)t14);
    t16 = ((char*)((ng16)));
    xsi_vlog_generic_get_array_select_value(t7, 32, t6, t11, t15, 2, 1, t16, 32, 1);
    xsi_vlogfile_write(1, 0, ng15, 2, t1, (char)118, t7, 32);
    xsi_set_current_line(137, ng0);
    t3 = (t1 + 8508);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 32U);
    t6 = *((char **)t5);
    t8 = (t1 + 8520);
    t9 = *((char **)t8);
    t10 = ((((char*)(t9))) + 40U);
    t11 = *((char **)t10);
    t12 = (t1 + 8532);
    t13 = *((char **)t12);
    t14 = ((((char*)(t13))) + 36U);
    t15 = *((char **)t14);
    t16 = ((char*)((ng18)));
    xsi_vlog_generic_get_array_select_value(t7, 32, t6, t11, t15, 2, 1, t16, 32, 1);
    xsi_vlogfile_write(1, 0, ng17, 2, t1, (char)118, t7, 32);
    xsi_set_current_line(138, ng0);
    t3 = (t1 + 8548);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 20U);
    t6 = *((char **)t5);
    xsi_vlogfile_write(1, 0, ng19, 2, t1, (char)118, t6, 32);
    xsi_set_current_line(139, ng0);
    t3 = (t1 + 8572);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 20U);
    t6 = *((char **)t5);
    xsi_vlogfile_write(1, 0, ng20, 2, t1, (char)118, t6, 32);
    xsi_set_current_line(141, ng0);
    t3 = (t1 + 8596);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 20U);
    t6 = *((char **)t5);
    t5 = ((char*)((ng21)));
    memset(t7, 0, 8);
    t8 = (t6 + 4U);
    t9 = (t5 + 4U);
    if (*((unsigned int *)t6) != *((unsigned int *)t5))
        goto LAB6;

LAB4:    if (*((unsigned int *)t8) != *((unsigned int *)t9))
        goto LAB6;

LAB5:    *((unsigned int *)t7) = 1;

LAB6:    t10 = (t7 + 4U);
    t17 = *((unsigned int *)t10);
    t18 = (~(t17));
    t19 = *((unsigned int *)t7);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB7;

LAB8:    xsi_set_current_line(143, ng0);
    t3 = (t1 + 8620);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 20U);
    t6 = *((char **)t5);
    t5 = ((char*)((ng23)));
    memset(t7, 0, 8);
    t8 = (t6 + 4U);
    t9 = (t5 + 4U);
    if (*((unsigned int *)t6) != *((unsigned int *)t5))
        goto LAB12;

LAB10:    if (*((unsigned int *)t8) != *((unsigned int *)t9))
        goto LAB12;

LAB11:    *((unsigned int *)t7) = 1;

LAB12:    t10 = (t7 + 4U);
    t17 = *((unsigned int *)t10);
    t18 = (~(t17));
    t19 = *((unsigned int *)t7);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB13;

LAB14:    xsi_set_current_line(145, ng0);
    t3 = (t1 + 8644);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 20U);
    t6 = *((char **)t5);
    t5 = ((char*)((ng5)));
    memset(t7, 0, 8);
    t8 = (t6 + 4U);
    t9 = (t5 + 4U);
    if (*((unsigned int *)t6) != *((unsigned int *)t5))
        goto LAB18;

LAB16:    if (*((unsigned int *)t8) != *((unsigned int *)t9))
        goto LAB18;

LAB17:    *((unsigned int *)t7) = 1;

LAB18:    t10 = (t7 + 4U);
    t17 = *((unsigned int *)t10);
    t18 = (~(t17));
    t19 = *((unsigned int *)t7);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB19;

LAB20:    xsi_set_current_line(147, ng0);
    t3 = (t1 + 8668);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 20U);
    t6 = *((char **)t5);
    t5 = ((char*)((ng26)));
    memset(t7, 0, 8);
    t8 = (t6 + 4U);
    t9 = (t5 + 4U);
    if (*((unsigned int *)t6) != *((unsigned int *)t5))
        goto LAB24;

LAB22:    if (*((unsigned int *)t8) != *((unsigned int *)t9))
        goto LAB24;

LAB23:    *((unsigned int *)t7) = 1;

LAB24:    t10 = (t7 + 4U);
    t17 = *((unsigned int *)t10);
    t18 = (~(t17));
    t19 = *((unsigned int *)t7);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB25;

LAB26:    xsi_set_current_line(150, ng0);
    t3 = (t1 + 8692);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 20U);
    t6 = *((char **)t5);
    xsi_vlogfile_write(1, 0, ng28, 2, t1, (char)118, t6, 32);

LAB27:
LAB21:
LAB15:
LAB9:
LAB2:    xsi_vlog_dispose_subprogram_invocation(t2);
    t0 = 0;

LAB1:    return t0;
LAB7:    xsi_set_current_line(142, ng0);
    xsi_vlogfile_write(1, 0, ng22, 1, t1);
    goto LAB9;

LAB13:    xsi_set_current_line(144, ng0);
    xsi_vlogfile_write(1, 0, ng24, 1, t1);
    goto LAB15;

LAB19:    xsi_set_current_line(146, ng0);
    xsi_vlogfile_write(1, 0, ng25, 1, t1);
    goto LAB21;

LAB25:    xsi_set_current_line(148, ng0);
    xsi_vlogfile_write(1, 0, ng27, 1, t1);
    goto LAB27;

}

static void I12_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(12, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1420);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void A13_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;

LAB0:    t1 = (t0 + 3588U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(13, ng0);
    t2 = (t0 + 3504);
    xsi_process_wait(t2, 5000000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(13, ng0);
    t4 = (t0 + 1420);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t3 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    *((unsigned int *)t3) = t10;
    *((unsigned int *)t7) = 0;
    if (*((unsigned int *)t8) != 0)
        goto LAB6;

LAB5:    t15 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t15 & 1U);
    t16 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t16 & 1U);
    t17 = (t0 + 1420);
    xsi_vlogvar_assign_value(t17, t3, 0, 0, 1);
    goto LAB2;

LAB6:    t11 = *((unsigned int *)t3);
    t12 = *((unsigned int *)t8);
    *((unsigned int *)t3) = (t11 | t12);
    t13 = *((unsigned int *)t7);
    t14 = *((unsigned int *)t8);
    *((unsigned int *)t7) = (t13 | t14);
    goto LAB5;

}

static void I16_2(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(16, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1604);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);

LAB1:    return;
}

static void A17_3(char *t0)
{
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;

LAB0:    t1 = (t0 + 3844U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(17, ng0);
    t2 = (t0 + 5688);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(17, ng0);
    t3 = (t0 + 1604);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng6)));
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t5, 32, t6, 32);
    t8 = (t0 + 1604);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    goto LAB2;

}

static void A50_4(char *t0)
{
    char t3[8];
    char t14[8];
    char t30[8];
    char t37[8];
    char t79[8];
    char t80[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    int t61;
    int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    char *t77;
    char *t78;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    char *t89;
    char *t90;
    char *t91;
    char *t92;
    char *t93;
    unsigned int t94;
    int t95;
    char *t96;
    unsigned int t97;
    int t98;
    int t99;
    unsigned int t100;
    unsigned int t101;
    int t102;
    int t103;

LAB0:    t1 = (t0 + 3972U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 5696);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(50, ng0);

LAB5:    xsi_set_current_line(51, ng0);
    t4 = (t0 + 1512);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t3 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t8) == 0)
        goto LAB6;

LAB8:    *((unsigned int *)t3) = 1;
    *((unsigned int *)t7) = 1;

LAB9:    memset(t14, 0, 8);
    t15 = (t14 + 4U);
    t16 = (t3 + 4U);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t3);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t16) != 0)
        goto LAB12;

LAB13:    t22 = (t14 + 4U);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t22);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB14;

LAB15:    memcpy(t37, t14, 8);

LAB16:    t69 = (t37 + 4U);
    t70 = *((unsigned int *)t69);
    t71 = (~(t70));
    t72 = *((unsigned int *)t37);
    t73 = (t72 & t71);
    t74 = (t73 != 0);
    if (t74 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t14) = 1;
    goto LAB13;

LAB12:    *((unsigned int *)t14) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB13;

LAB14:    t26 = (t0 + 8720);
    t27 = *((char **)t26);
    t28 = ((((char*)(t27))) + 20U);
    t29 = *((char **)t28);
    memset(t30, 0, 8);
    t28 = (t30 + 4U);
    t31 = (t29 + 4U);
    t32 = *((unsigned int *)t31);
    t33 = (~(t32));
    t34 = *((unsigned int *)t29);
    t35 = (t34 & t33);
    t36 = (t35 & 1U);
    if (t36 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t31) != 0)
        goto LAB19;

LAB20:    t38 = *((unsigned int *)t14);
    t39 = *((unsigned int *)t30);
    t40 = (t38 & t39);
    *((unsigned int *)t37) = t40;
    t41 = (t14 + 4U);
    t42 = (t30 + 4U);
    t43 = (t37 + 4U);
    t44 = *((unsigned int *)t41);
    t45 = *((unsigned int *)t42);
    t46 = (t44 | t45);
    *((unsigned int *)t43) = t46;
    t47 = *((unsigned int *)t43);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t30) = 1;
    goto LAB20;

LAB19:    *((unsigned int *)t30) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB20;

LAB21:    t49 = *((unsigned int *)t37);
    t50 = *((unsigned int *)t43);
    *((unsigned int *)t37) = (t49 | t50);
    t51 = (t14 + 4U);
    t52 = (t30 + 4U);
    t53 = *((unsigned int *)t14);
    t54 = (~(t53));
    t55 = *((unsigned int *)t51);
    t56 = (~(t55));
    t57 = *((unsigned int *)t30);
    t58 = (~(t57));
    t59 = *((unsigned int *)t52);
    t60 = (~(t59));
    t61 = (t54 & t56);
    t62 = (t58 & t60);
    t63 = (~(t61));
    t64 = (~(t62));
    t65 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t65 & t63);
    t66 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t66 & t64);
    t67 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t67 & t63);
    t68 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t68 & t64);
    goto LAB23;

LAB24:    xsi_set_current_line(51, ng0);

LAB27:    xsi_set_current_line(52, ng0);
    t75 = (t0 + 8744);
    t76 = *((char **)t75);
    t77 = ((((char*)(t76))) + 20U);
    t78 = *((char **)t77);
    t77 = (t0 + 1696);
    t81 = (t0 + 1696);
    t82 = (t81 + 40U);
    t83 = *((char **)t82);
    t84 = (t0 + 1696);
    t85 = (t84 + 36U);
    t86 = *((char **)t85);
    t87 = (t0 + 8776);
    t88 = *((char **)t87);
    t89 = ((((char*)(t88))) + 20U);
    t90 = *((char **)t89);
    t89 = (t0 + 8800);
    t91 = *((char **)t89);
    t92 = ((((char*)(t91))) + 20U);
    t93 = *((char **)t92);
    xsi_vlog_generic_convert_array_indices(t79, t80, t83, t86, 2, 2, t90, 2, 2, t93, 4, 2);
    t92 = (t79 + 4U);
    t94 = *((unsigned int *)t92);
    t95 = (!(t94));
    t96 = (t80 + 4U);
    t97 = *((unsigned int *)t96);
    t98 = (!(t97));
    t99 = (t95 && t98);
    if (t99 == 1)
        goto LAB28;

LAB29:    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng29)));
    t4 = (t0 + 1788);
    t5 = (t0 + 1788);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    t8 = (t0 + 1788);
    t15 = (t8 + 36U);
    t16 = *((char **)t15);
    t22 = (t0 + 8832);
    t26 = *((char **)t22);
    t27 = ((((char*)(t26))) + 20U);
    t28 = *((char **)t27);
    t27 = (t0 + 8856);
    t29 = *((char **)t27);
    t31 = ((((char*)(t29))) + 20U);
    t41 = *((char **)t31);
    xsi_vlog_generic_convert_array_indices(t3, t14, t7, t16, 2, 2, t28, 2, 2, t41, 4, 2);
    t31 = (t3 + 4U);
    t9 = *((unsigned int *)t31);
    t61 = (!(t9));
    t42 = (t14 + 4U);
    t10 = *((unsigned int *)t42);
    t62 = (!(t10));
    t95 = (t61 && t62);
    if (t95 == 1)
        goto LAB30;

LAB31:    goto LAB26;

LAB28:    t100 = *((unsigned int *)t79);
    t101 = *((unsigned int *)t80);
    t102 = (t100 - t101);
    t103 = (t102 + 1);
    xsi_vlogvar_generic_wait_assign_value(t77, t78, 2, 0, *((unsigned int *)t80), t103, 0LL);
    goto LAB29;

LAB30:    t11 = *((unsigned int *)t3);
    t12 = *((unsigned int *)t14);
    t98 = (t11 - t12);
    t99 = (t98 + 1);
    xsi_vlogvar_generic_wait_assign_value(t4, t2, 2, 0, *((unsigned int *)t14), t99, 0LL);
    goto LAB31;

}

static void A65_5(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;

LAB0:    t1 = (t0 + 4100U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(65, ng0);
    t2 = (t0 + 5704);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(65, ng0);

LAB5:    xsi_set_current_line(66, ng0);
    t3 = (t0 + 8884);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 20U);
    t6 = *((char **)t5);
    t5 = (t0 + 2064);
    xsi_vlogvar_generic_wait_assign_value(t5, t6, 2, 0, 0, 1, 0LL);
    xsi_set_current_line(67, ng0);
    t2 = (t0 + 8908);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 20U);
    t5 = *((char **)t4);
    t4 = (t0 + 2156);
    xsi_vlogvar_generic_wait_assign_value(t4, t5, 2, 0, 0, 4, 0LL);
    xsi_set_current_line(68, ng0);
    t2 = (t0 + 8932);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 20U);
    t5 = *((char **)t4);
    t4 = (t0 + 2248);
    xsi_vlogvar_generic_wait_assign_value(t4, t5, 2, 0, 0, 32, 0LL);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 8964);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 20U);
    t5 = *((char **)t4);
    t4 = (t0 + 2340);
    xsi_vlogvar_generic_wait_assign_value(t4, t5, 2, 0, 0, 2, 0LL);
    goto LAB2;

}

static void A72_6(char *t0)
{
    char t3[8];
    char t14[8];
    char t29[8];
    char t37[8];
    char t75[8];
    char t79[8];
    char t109[8];
    char t110[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    int t61;
    int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t76;
    char *t77;
    char *t78;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    char *t89;
    char *t90;
    char *t91;
    char *t92;
    char *t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    char *t105;
    char *t106;
    char *t107;
    char *t108;
    char *t111;
    char *t112;
    char *t113;
    char *t114;
    char *t115;
    char *t116;
    char *t117;
    char *t118;
    char *t119;
    char *t120;
    char *t121;
    char *t122;
    char *t123;
    unsigned int t124;
    int t125;
    char *t126;
    unsigned int t127;
    int t128;
    int t129;
    unsigned int t130;
    unsigned int t131;
    int t132;
    int t133;

LAB0:    t1 = (t0 + 4228U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 5712);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(72, ng0);

LAB5:    xsi_set_current_line(73, ng0);
    t4 = (t0 + 1512);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t3 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t8) == 0)
        goto LAB6;

LAB8:    *((unsigned int *)t3) = 1;
    *((unsigned int *)t7) = 1;

LAB9:    memset(t14, 0, 8);
    t15 = (t14 + 4U);
    t16 = (t3 + 4U);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t3);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t16) != 0)
        goto LAB12;

LAB13:    t22 = (t14 + 4U);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t22);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB14;

LAB15:    memcpy(t37, t14, 8);

LAB16:    t69 = (t37 + 4U);
    t70 = *((unsigned int *)t69);
    t71 = (~(t70));
    t72 = *((unsigned int *)t37);
    t73 = (t72 & t71);
    t74 = (t73 != 0);
    if (t74 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t14) = 1;
    goto LAB13;

LAB12:    *((unsigned int *)t14) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB13;

LAB14:    t26 = (t0 + 2064);
    t27 = (t26 + 32U);
    t28 = *((char **)t27);
    memset(t29, 0, 8);
    t30 = (t29 + 4U);
    t31 = (t28 + 4U);
    t32 = *((unsigned int *)t31);
    t33 = (~(t32));
    t34 = *((unsigned int *)t28);
    t35 = (t34 & t33);
    t36 = (t35 & 1U);
    if (t36 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t31) != 0)
        goto LAB19;

LAB20:    t38 = *((unsigned int *)t14);
    t39 = *((unsigned int *)t29);
    t40 = (t38 & t39);
    *((unsigned int *)t37) = t40;
    t41 = (t14 + 4U);
    t42 = (t29 + 4U);
    t43 = (t37 + 4U);
    t44 = *((unsigned int *)t41);
    t45 = *((unsigned int *)t42);
    t46 = (t44 | t45);
    *((unsigned int *)t43) = t46;
    t47 = *((unsigned int *)t43);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t29) = 1;
    goto LAB20;

LAB19:    *((unsigned int *)t29) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB20;

LAB21:    t49 = *((unsigned int *)t37);
    t50 = *((unsigned int *)t43);
    *((unsigned int *)t37) = (t49 | t50);
    t51 = (t14 + 4U);
    t52 = (t29 + 4U);
    t53 = *((unsigned int *)t14);
    t54 = (~(t53));
    t55 = *((unsigned int *)t51);
    t56 = (~(t55));
    t57 = *((unsigned int *)t29);
    t58 = (~(t57));
    t59 = *((unsigned int *)t52);
    t60 = (~(t59));
    t61 = (t54 & t56);
    t62 = (t58 & t60);
    t63 = (~(t61));
    t64 = (~(t62));
    t65 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t65 & t63);
    t66 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t66 & t64);
    t67 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t67 & t63);
    t68 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t68 & t64);
    goto LAB23;

LAB24:    xsi_set_current_line(73, ng0);

LAB27:    xsi_set_current_line(75, ng0);
    t76 = (t0 + 1788);
    t77 = (t76 + 32U);
    t78 = *((char **)t77);
    t80 = (t0 + 1788);
    t81 = (t80 + 40U);
    t82 = *((char **)t81);
    t83 = (t0 + 1788);
    t84 = (t83 + 36U);
    t85 = *((char **)t84);
    t86 = (t0 + 2340);
    t87 = (t86 + 32U);
    t88 = *((char **)t87);
    t89 = (t0 + 2156);
    t90 = (t89 + 32U);
    t91 = *((char **)t90);
    xsi_vlog_generic_get_array_select_value(t79, 1, t78, t82, t85, 2, 2, t88, 2, 2, t91, 4, 2);
    memset(t75, 0, 8);
    t92 = (t75 + 4U);
    t93 = (t79 + 4U);
    t94 = *((unsigned int *)t93);
    t95 = (~(t94));
    t96 = *((unsigned int *)t79);
    t97 = (t96 & t95);
    t98 = (t97 & 1U);
    if (t98 != 0)
        goto LAB31;

LAB29:    if (*((unsigned int *)t93) == 0)
        goto LAB28;

LAB30:    *((unsigned int *)t75) = 1;
    *((unsigned int *)t92) = 1;

LAB31:    t99 = (t75 + 4U);
    t100 = *((unsigned int *)t99);
    t101 = (~(t100));
    t102 = *((unsigned int *)t75);
    t103 = (t102 & t101);
    t104 = (t103 != 0);
    if (t104 > 0)
        goto LAB32;

LAB33:
LAB34:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 1604);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 2340);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t15 = (t0 + 2156);
    t16 = (t15 + 32U);
    t22 = *((char **)t16);
    t26 = (t0 + 2248);
    t27 = (t26 + 32U);
    t28 = *((char **)t27);
    t30 = (t0 + 2248);
    t31 = (t30 + 32U);
    t41 = *((char **)t31);
    xsi_vlogfile_write(1, 0, ng30, 6, t0, (char)119, t5, 32, (char)118, t8, 2, (char)118, t22, 4, (char)118, t28, 32, (char)118, t41, 32);
    goto LAB26;

LAB28:    *((unsigned int *)t75) = 1;
    goto LAB31;

LAB32:    xsi_set_current_line(75, ng0);

LAB35:    xsi_set_current_line(76, ng0);
    t105 = (t0 + 2248);
    t106 = (t105 + 32U);
    t107 = *((char **)t106);
    t108 = (t0 + 1696);
    t111 = (t0 + 1696);
    t112 = (t111 + 40U);
    t113 = *((char **)t112);
    t114 = (t0 + 1696);
    t115 = (t114 + 36U);
    t116 = *((char **)t115);
    t117 = (t0 + 2340);
    t118 = (t117 + 32U);
    t119 = *((char **)t118);
    t120 = (t0 + 2156);
    t121 = (t120 + 32U);
    t122 = *((char **)t121);
    xsi_vlog_generic_convert_array_indices(t109, t110, t113, t116, 2, 2, t119, 2, 2, t122, 4, 2);
    t123 = (t109 + 4U);
    t124 = *((unsigned int *)t123);
    t125 = (!(t124));
    t126 = (t110 + 4U);
    t127 = *((unsigned int *)t126);
    t128 = (!(t127));
    t129 = (t125 && t128);
    if (t129 == 1)
        goto LAB36;

LAB37:    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng29)));
    t4 = (t0 + 1788);
    t5 = (t0 + 1788);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    t8 = (t0 + 1788);
    t15 = (t8 + 36U);
    t16 = *((char **)t15);
    t22 = (t0 + 2340);
    t26 = (t22 + 32U);
    t27 = *((char **)t26);
    t28 = (t0 + 2156);
    t30 = (t28 + 32U);
    t31 = *((char **)t30);
    xsi_vlog_generic_convert_array_indices(t3, t14, t7, t16, 2, 2, t27, 2, 2, t31, 4, 2);
    t41 = (t3 + 4U);
    t9 = *((unsigned int *)t41);
    t61 = (!(t9));
    t42 = (t14 + 4U);
    t10 = *((unsigned int *)t42);
    t62 = (!(t10));
    t125 = (t61 && t62);
    if (t125 == 1)
        goto LAB38;

LAB39:    goto LAB34;

LAB36:    t130 = *((unsigned int *)t109);
    t131 = *((unsigned int *)t110);
    t132 = (t130 - t131);
    t133 = (t132 + 1);
    xsi_vlogvar_generic_wait_assign_value(t108, t107, 2, 0, *((unsigned int *)t110), t133, 0LL);
    goto LAB37;

LAB38:    t11 = *((unsigned int *)t3);
    t12 = *((unsigned int *)t14);
    t128 = (t11 - t12);
    t129 = (t128 + 1);
    xsi_vlogvar_generic_wait_assign_value(t4, t2, 2, 0, *((unsigned int *)t14), t129, 0LL);
    goto LAB39;

}

static void I88_7(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(88, ng0);

LAB2:    xsi_set_current_line(89, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2432);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);
    xsi_set_current_line(90, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2524);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);

LAB1:    return;
}

static void A160_8(char *t0)
{
    char t3[8];
    char t14[8];
    char t30[8];
    char t31[8];
    char t39[8];
    char t89[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    char *t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    int t63;
    int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    char *t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    char *t90;
    char *t91;
    char *t92;
    char *t93;
    char *t94;
    char *t95;
    char *t96;
    char *t97;
    char *t98;
    char *t99;
    char *t100;
    char *t101;
    char *t102;

LAB0:    t1 = (t0 + 4484U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(160, ng0);
    t2 = (t0 + 5720);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(160, ng0);

LAB5:    xsi_set_current_line(161, ng0);
    t4 = (t0 + 1512);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t3 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t8) == 0)
        goto LAB6;

LAB8:    *((unsigned int *)t3) = 1;
    *((unsigned int *)t7) = 1;

LAB9:    memset(t14, 0, 8);
    t15 = (t14 + 4U);
    t16 = (t3 + 4U);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t3);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t16) != 0)
        goto LAB12;

LAB13:    t22 = (t14 + 4U);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t22);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB14;

LAB15:    memcpy(t39, t14, 8);

LAB16:    t71 = (t39 + 4U);
    t72 = *((unsigned int *)t71);
    t73 = (~(t72));
    t74 = *((unsigned int *)t39);
    t75 = (t74 & t73);
    t76 = (t75 != 0);
    if (t76 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t14) = 1;
    goto LAB13;

LAB12:    *((unsigned int *)t14) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB13;

LAB14:    t26 = (t0 + 1604);
    t27 = (t26 + 32U);
    t28 = *((char **)t27);
    t29 = ((char*)((ng31)));
    memset(t30, 0, 8);
    xsi_vlog_signed_leq(t30, 32, t28, 32, t29, 32);
    memset(t31, 0, 8);
    t32 = (t31 + 4U);
    t33 = (t30 + 4U);
    t34 = *((unsigned int *)t33);
    t35 = (~(t34));
    t36 = *((unsigned int *)t30);
    t37 = (t36 & t35);
    t38 = (t37 & 1U);
    if (t38 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t33) != 0)
        goto LAB19;

LAB20:    t40 = *((unsigned int *)t14);
    t41 = *((unsigned int *)t31);
    t42 = (t40 & t41);
    *((unsigned int *)t39) = t42;
    t43 = (t14 + 4U);
    t44 = (t31 + 4U);
    t45 = (t39 + 4U);
    t46 = *((unsigned int *)t43);
    t47 = *((unsigned int *)t44);
    t48 = (t46 | t47);
    *((unsigned int *)t45) = t48;
    t49 = *((unsigned int *)t45);
    t50 = (t49 != 0);
    if (t50 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t31) = 1;
    goto LAB20;

LAB19:    *((unsigned int *)t31) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB20;

LAB21:    t51 = *((unsigned int *)t39);
    t52 = *((unsigned int *)t45);
    *((unsigned int *)t39) = (t51 | t52);
    t53 = (t14 + 4U);
    t54 = (t31 + 4U);
    t55 = *((unsigned int *)t14);
    t56 = (~(t55));
    t57 = *((unsigned int *)t53);
    t58 = (~(t57));
    t59 = *((unsigned int *)t31);
    t60 = (~(t59));
    t61 = *((unsigned int *)t54);
    t62 = (~(t61));
    t63 = (t56 & t58);
    t64 = (t60 & t62);
    t65 = (~(t63));
    t66 = (~(t64));
    t67 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t67 & t65);
    t68 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t68 & t66);
    t69 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t69 & t65);
    t70 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t70 & t66);
    goto LAB23;

LAB24:    xsi_set_current_line(162, ng0);
    t77 = (t0 + 1604);
    t78 = (t77 + 32U);
    t79 = *((char **)t78);
    t80 = (t0 + 8992);
    t81 = *((char **)t80);
    t82 = ((((char*)(t81))) + 32U);
    t83 = *((char **)t82);
    t84 = (t0 + 9020);
    t85 = *((char **)t84);
    t86 = ((((char*)(t85))) + 32U);
    t87 = *((char **)t86);
    t88 = ((char*)((ng6)));
    memset(t89, 0, 8);
    xsi_vlog_unsigned_minus(t89, 32, t87, 32, t88, 32);
    t90 = (t0 + 9044);
    t91 = *((char **)t90);
    t92 = ((((char*)(t91))) + 20U);
    t93 = *((char **)t92);
    t92 = (t0 + 9068);
    t94 = *((char **)t92);
    t95 = ((((char*)(t94))) + 20U);
    t96 = *((char **)t95);
    t95 = (t0 + 9092);
    t97 = *((char **)t95);
    t98 = ((((char*)(t97))) + 20U);
    t99 = *((char **)t98);
    t98 = (t0 + 9124);
    t100 = *((char **)t98);
    t101 = ((((char*)(t100))) + 20U);
    t102 = *((char **)t101);
    xsi_vlogfile_write(1, 0, ng32, 8, t0, (char)119, t79, 32, (char)118, t83, 2, (char)118, t89, 32, (char)118, t93, 32, (char)118, t96, 2, (char)118, t99, 2, (char)118, t102, 2);
    goto LAB26;

}

static void A174_9(char *t0)
{
    char t3[8];
    char t14[8];
    char t30[8];
    char t37[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    int t61;
    int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    char *t89;
    char *t90;

LAB0:    t1 = (t0 + 4612U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(174, ng0);
    t2 = (t0 + 5728);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(174, ng0);

LAB5:    xsi_set_current_line(175, ng0);
    t4 = (t0 + 1512);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t3 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t8) == 0)
        goto LAB6;

LAB8:    *((unsigned int *)t3) = 1;
    *((unsigned int *)t7) = 1;

LAB9:    memset(t14, 0, 8);
    t15 = (t14 + 4U);
    t16 = (t3 + 4U);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t3);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t16) != 0)
        goto LAB12;

LAB13:    t22 = (t14 + 4U);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t22);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB14;

LAB15:    memcpy(t37, t14, 8);

LAB16:    t69 = (t37 + 4U);
    t70 = *((unsigned int *)t69);
    t71 = (~(t70));
    t72 = *((unsigned int *)t37);
    t73 = (t72 & t71);
    t74 = (t73 != 0);
    if (t74 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t14) = 1;
    goto LAB13;

LAB12:    *((unsigned int *)t14) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB13;

LAB14:    t26 = (t0 + 9152);
    t27 = *((char **)t26);
    t28 = ((((char*)(t27))) + 20U);
    t29 = *((char **)t28);
    memset(t30, 0, 8);
    t28 = (t30 + 4U);
    t31 = (t29 + 4U);
    t32 = *((unsigned int *)t31);
    t33 = (~(t32));
    t34 = *((unsigned int *)t29);
    t35 = (t34 & t33);
    t36 = (t35 & 1U);
    if (t36 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t31) != 0)
        goto LAB19;

LAB20:    t38 = *((unsigned int *)t14);
    t39 = *((unsigned int *)t30);
    t40 = (t38 & t39);
    *((unsigned int *)t37) = t40;
    t41 = (t14 + 4U);
    t42 = (t30 + 4U);
    t43 = (t37 + 4U);
    t44 = *((unsigned int *)t41);
    t45 = *((unsigned int *)t42);
    t46 = (t44 | t45);
    *((unsigned int *)t43) = t46;
    t47 = *((unsigned int *)t43);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t30) = 1;
    goto LAB20;

LAB19:    *((unsigned int *)t30) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB20;

LAB21:    t49 = *((unsigned int *)t37);
    t50 = *((unsigned int *)t43);
    *((unsigned int *)t37) = (t49 | t50);
    t51 = (t14 + 4U);
    t52 = (t30 + 4U);
    t53 = *((unsigned int *)t14);
    t54 = (~(t53));
    t55 = *((unsigned int *)t51);
    t56 = (~(t55));
    t57 = *((unsigned int *)t30);
    t58 = (~(t57));
    t59 = *((unsigned int *)t52);
    t60 = (~(t59));
    t61 = (t54 & t56);
    t62 = (t58 & t60);
    t63 = (~(t61));
    t64 = (~(t62));
    t65 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t65 & t63);
    t66 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t66 & t64);
    t67 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t67 & t63);
    t68 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t68 & t64);
    goto LAB23;

LAB24:    xsi_set_current_line(176, ng0);
    t75 = (t0 + 1604);
    t76 = (t75 + 32U);
    t77 = *((char **)t76);
    t78 = (t0 + 9184);
    t79 = *((char **)t78);
    t80 = ((((char*)(t79))) + 20U);
    t81 = *((char **)t80);
    t80 = (t0 + 9208);
    t82 = *((char **)t80);
    t83 = ((((char*)(t82))) + 20U);
    t84 = *((char **)t83);
    t83 = (t0 + 9232);
    t85 = *((char **)t83);
    t86 = ((((char*)(t85))) + 20U);
    t87 = *((char **)t86);
    t86 = (t0 + 9256);
    t88 = *((char **)t86);
    t89 = ((((char*)(t88))) + 20U);
    t90 = *((char **)t89);
    xsi_vlogfile_write(1, 0, ng33, 6, t0, (char)119, t77, 32, (char)118, t81, 2, (char)118, t84, 4, (char)118, t87, 32, (char)118, t90, 32);
    goto LAB26;

}

static void A185_10(char *t0)
{
    char t3[8];
    char t14[8];
    char t26[8];
    char t37[8];
    char t45[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    char *t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    int t69;
    int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    char *t89;
    char *t90;
    char *t91;
    char *t92;

LAB0:    t1 = (t0 + 4740U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(185, ng0);
    t2 = (t0 + 5736);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(185, ng0);

LAB5:    xsi_set_current_line(186, ng0);
    t4 = (t0 + 1512);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t3 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t8) == 0)
        goto LAB6;

LAB8:    *((unsigned int *)t3) = 1;
    *((unsigned int *)t7) = 1;

LAB9:    memset(t14, 0, 8);
    t15 = (t14 + 4U);
    t16 = (t3 + 4U);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t3);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t16) != 0)
        goto LAB12;

LAB13:    t22 = (t14 + 4U);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t22);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB14;

LAB15:    memcpy(t45, t14, 8);

LAB16:    t77 = (t45 + 4U);
    t78 = *((unsigned int *)t77);
    t79 = (~(t78));
    t80 = *((unsigned int *)t45);
    t81 = (t80 & t79);
    t82 = (t81 != 0);
    if (t82 > 0)
        goto LAB28;

LAB29:
LAB30:    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t14) = 1;
    goto LAB13;

LAB12:    *((unsigned int *)t14) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB13;

LAB14:    t27 = (t0 + 9280);
    t28 = *((char **)t27);
    t29 = ((((char*)(t28))) + 20U);
    t30 = *((char **)t29);
    memset(t26, 0, 8);
    t29 = (t26 + 4U);
    t31 = (t30 + 4U);
    t32 = *((unsigned int *)t31);
    t33 = (~(t32));
    t34 = *((unsigned int *)t30);
    t35 = (t34 & t33);
    t36 = (t35 & 1U);
    if (t36 != 0)
        goto LAB20;

LAB18:    if (*((unsigned int *)t31) == 0)
        goto LAB17;

LAB19:    *((unsigned int *)t26) = 1;
    *((unsigned int *)t29) = 1;

LAB20:    memset(t37, 0, 8);
    t38 = (t37 + 4U);
    t39 = (t26 + 4U);
    t40 = *((unsigned int *)t39);
    t41 = (~(t40));
    t42 = *((unsigned int *)t26);
    t43 = (t42 & t41);
    t44 = (t43 & 1U);
    if (t44 != 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t39) != 0)
        goto LAB23;

LAB24:    t46 = *((unsigned int *)t14);
    t47 = *((unsigned int *)t37);
    t48 = (t46 & t47);
    *((unsigned int *)t45) = t48;
    t49 = (t14 + 4U);
    t50 = (t37 + 4U);
    t51 = (t45 + 4U);
    t52 = *((unsigned int *)t49);
    t53 = *((unsigned int *)t50);
    t54 = (t52 | t53);
    *((unsigned int *)t51) = t54;
    t55 = *((unsigned int *)t51);
    t56 = (t55 != 0);
    if (t56 == 1)
        goto LAB25;

LAB26:
LAB27:    goto LAB16;

LAB17:    *((unsigned int *)t26) = 1;
    goto LAB20;

LAB21:    *((unsigned int *)t37) = 1;
    goto LAB24;

LAB23:    *((unsigned int *)t37) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB24;

LAB25:    t57 = *((unsigned int *)t45);
    t58 = *((unsigned int *)t51);
    *((unsigned int *)t45) = (t57 | t58);
    t59 = (t14 + 4U);
    t60 = (t37 + 4U);
    t61 = *((unsigned int *)t14);
    t62 = (~(t61));
    t63 = *((unsigned int *)t59);
    t64 = (~(t63));
    t65 = *((unsigned int *)t37);
    t66 = (~(t65));
    t67 = *((unsigned int *)t60);
    t68 = (~(t67));
    t69 = (t62 & t64);
    t70 = (t66 & t68);
    t71 = (~(t69));
    t72 = (~(t70));
    t73 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t73 & t71);
    t74 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t74 & t72);
    t75 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t75 & t71);
    t76 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t76 & t72);
    goto LAB27;

LAB28:    xsi_set_current_line(187, ng0);
    t83 = (t0 + 1604);
    t84 = (t83 + 32U);
    t85 = *((char **)t84);
    t86 = (t0 + 9304);
    t87 = *((char **)t86);
    t88 = ((((char*)(t87))) + 20U);
    t89 = *((char **)t88);
    t88 = (t0 + 9324);
    t90 = *((char **)t88);
    t91 = ((((char*)(t90))) + 20U);
    t92 = *((char **)t91);
    xsi_vlogfile_write(1, 0, ng34, 4, t0, (char)119, t85, 32, (char)118, t89, 2, (char)118, t92, 4);
    goto LAB30;

}

static void A192_11(char *t0)
{
    char t3[8];
    char t14[8];
    char t30[8];
    char t46[8];
    char t63[8];
    char t79[8];
    char t87[8];
    char t115[8];
    char t123[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    char *t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;
    char *t61;
    char *t62;
    char *t64;
    char *t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    char *t80;
    char *t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    char *t91;
    char *t92;
    char *t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    char *t101;
    char *t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    char *t116;
    char *t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    char *t127;
    char *t128;
    char *t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    char *t137;
    char *t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    int t147;
    int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;
    char *t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    char *t161;
    char *t162;
    char *t163;
    char *t164;
    char *t165;
    char *t166;
    char *t167;
    char *t168;
    char *t169;
    char *t170;
    char *t171;
    char *t172;
    char *t173;

LAB0:    t1 = (t0 + 4868U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(192, ng0);
    t2 = (t0 + 5744);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(192, ng0);

LAB5:    xsi_set_current_line(193, ng0);
    t4 = (t0 + 1512);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t3 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t8) == 0)
        goto LAB6;

LAB8:    *((unsigned int *)t3) = 1;
    *((unsigned int *)t7) = 1;

LAB9:    memset(t14, 0, 8);
    t15 = (t14 + 4U);
    t16 = (t3 + 4U);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t3);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t16) != 0)
        goto LAB12;

LAB13:    t22 = (t14 + 4U);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t22);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB14;

LAB15:    memcpy(t123, t14, 8);

LAB16:    t155 = (t123 + 4U);
    t156 = *((unsigned int *)t155);
    t157 = (~(t156));
    t158 = *((unsigned int *)t123);
    t159 = (t158 & t157);
    t160 = (t159 != 0);
    if (t160 > 0)
        goto LAB46;

LAB47:
LAB48:    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t14) = 1;
    goto LAB13;

LAB12:    *((unsigned int *)t14) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB13;

LAB14:    t26 = (t0 + 9344);
    t27 = *((char **)t26);
    t28 = ((((char*)(t27))) + 20U);
    t29 = *((char **)t28);
    t28 = ((char*)((ng5)));
    memset(t30, 0, 8);
    t31 = (t30 + 4U);
    t32 = (t29 + 4U);
    t33 = (t28 + 4U);
    t34 = *((unsigned int *)t29);
    t35 = *((unsigned int *)t28);
    t36 = (t34 ^ t35);
    t37 = *((unsigned int *)t32);
    t38 = *((unsigned int *)t33);
    t39 = (t37 ^ t38);
    t40 = (t36 | t39);
    t41 = *((unsigned int *)t32);
    t42 = *((unsigned int *)t33);
    t43 = (t41 | t42);
    t44 = (~(t43));
    t45 = (t40 & t44);
    if (t45 != 0)
        goto LAB18;

LAB17:    if (t43 != 0)
        goto LAB19;

LAB20:    memset(t46, 0, 8);
    t47 = (t46 + 4U);
    t48 = (t30 + 4U);
    t49 = *((unsigned int *)t48);
    t50 = (~(t49));
    t51 = *((unsigned int *)t30);
    t52 = (t51 & t50);
    t53 = (t52 & 1U);
    if (t53 != 0)
        goto LAB21;

LAB22:    if (*((unsigned int *)t48) != 0)
        goto LAB23;

LAB24:    t54 = (t46 + 4U);
    t55 = *((unsigned int *)t46);
    t56 = (!(t55));
    t57 = *((unsigned int *)t54);
    t58 = (t56 || t57);
    if (t58 > 0)
        goto LAB25;

LAB26:    memcpy(t87, t46, 8);

LAB27:    memset(t115, 0, 8);
    t116 = (t115 + 4U);
    t117 = (t87 + 4U);
    t118 = *((unsigned int *)t117);
    t119 = (~(t118));
    t120 = *((unsigned int *)t87);
    t121 = (t120 & t119);
    t122 = (t121 & 1U);
    if (t122 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t117) != 0)
        goto LAB41;

LAB42:    t124 = *((unsigned int *)t14);
    t125 = *((unsigned int *)t115);
    t126 = (t124 & t125);
    *((unsigned int *)t123) = t126;
    t127 = (t14 + 4U);
    t128 = (t115 + 4U);
    t129 = (t123 + 4U);
    t130 = *((unsigned int *)t127);
    t131 = *((unsigned int *)t128);
    t132 = (t130 | t131);
    *((unsigned int *)t129) = t132;
    t133 = *((unsigned int *)t129);
    t134 = (t133 != 0);
    if (t134 == 1)
        goto LAB43;

LAB44:
LAB45:    goto LAB16;

LAB18:    *((unsigned int *)t30) = 1;
    goto LAB20;

LAB19:    *((unsigned int *)t30) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB20;

LAB21:    *((unsigned int *)t46) = 1;
    goto LAB24;

LAB23:    *((unsigned int *)t46) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB24;

LAB25:    t59 = (t0 + 9364);
    t60 = *((char **)t59);
    t61 = ((((char*)(t60))) + 20U);
    t62 = *((char **)t61);
    t61 = ((char*)((ng5)));
    memset(t63, 0, 8);
    t64 = (t63 + 4U);
    t65 = (t62 + 4U);
    t66 = (t61 + 4U);
    t67 = *((unsigned int *)t62);
    t68 = *((unsigned int *)t61);
    t69 = (t67 ^ t68);
    t70 = *((unsigned int *)t65);
    t71 = *((unsigned int *)t66);
    t72 = (t70 ^ t71);
    t73 = (t69 | t72);
    t74 = *((unsigned int *)t65);
    t75 = *((unsigned int *)t66);
    t76 = (t74 | t75);
    t77 = (~(t76));
    t78 = (t73 & t77);
    if (t78 != 0)
        goto LAB29;

LAB28:    if (t76 != 0)
        goto LAB30;

LAB31:    memset(t79, 0, 8);
    t80 = (t79 + 4U);
    t81 = (t63 + 4U);
    t82 = *((unsigned int *)t81);
    t83 = (~(t82));
    t84 = *((unsigned int *)t63);
    t85 = (t84 & t83);
    t86 = (t85 & 1U);
    if (t86 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t81) != 0)
        goto LAB34;

LAB35:    t88 = *((unsigned int *)t46);
    t89 = *((unsigned int *)t79);
    t90 = (t88 | t89);
    *((unsigned int *)t87) = t90;
    t91 = (t46 + 4U);
    t92 = (t79 + 4U);
    t93 = (t87 + 4U);
    t94 = *((unsigned int *)t91);
    t95 = *((unsigned int *)t92);
    t96 = (t94 | t95);
    *((unsigned int *)t93) = t96;
    t97 = *((unsigned int *)t93);
    t98 = (t97 != 0);
    if (t98 == 1)
        goto LAB36;

LAB37:
LAB38:    goto LAB27;

LAB29:    *((unsigned int *)t63) = 1;
    goto LAB31;

LAB30:    *((unsigned int *)t63) = 1;
    *((unsigned int *)t64) = 1;
    goto LAB31;

LAB32:    *((unsigned int *)t79) = 1;
    goto LAB35;

LAB34:    *((unsigned int *)t79) = 1;
    *((unsigned int *)t80) = 1;
    goto LAB35;

LAB36:    t99 = *((unsigned int *)t87);
    t100 = *((unsigned int *)t93);
    *((unsigned int *)t87) = (t99 | t100);
    t101 = (t46 + 4U);
    t102 = (t79 + 4U);
    t103 = *((unsigned int *)t101);
    t104 = (~(t103));
    t105 = *((unsigned int *)t46);
    t106 = (t105 & t104);
    t107 = *((unsigned int *)t102);
    t108 = (~(t107));
    t109 = *((unsigned int *)t79);
    t110 = (t109 & t108);
    t111 = (~(t106));
    t112 = (~(t110));
    t113 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t113 & t111);
    t114 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t114 & t112);
    goto LAB38;

LAB39:    *((unsigned int *)t115) = 1;
    goto LAB42;

LAB41:    *((unsigned int *)t115) = 1;
    *((unsigned int *)t116) = 1;
    goto LAB42;

LAB43:    t135 = *((unsigned int *)t123);
    t136 = *((unsigned int *)t129);
    *((unsigned int *)t123) = (t135 | t136);
    t137 = (t14 + 4U);
    t138 = (t115 + 4U);
    t139 = *((unsigned int *)t14);
    t140 = (~(t139));
    t141 = *((unsigned int *)t137);
    t142 = (~(t141));
    t143 = *((unsigned int *)t115);
    t144 = (~(t143));
    t145 = *((unsigned int *)t138);
    t146 = (~(t145));
    t147 = (t140 & t142);
    t148 = (t144 & t146);
    t149 = (~(t147));
    t150 = (~(t148));
    t151 = *((unsigned int *)t129);
    *((unsigned int *)t129) = (t151 & t149);
    t152 = *((unsigned int *)t129);
    *((unsigned int *)t129) = (t152 & t150);
    t153 = *((unsigned int *)t123);
    *((unsigned int *)t123) = (t153 & t149);
    t154 = *((unsigned int *)t123);
    *((unsigned int *)t123) = (t154 & t150);
    goto LAB45;

LAB46:    xsi_set_current_line(194, ng0);
    t161 = (t0 + 1604);
    t162 = (t161 + 32U);
    t163 = *((char **)t162);
    t164 = (t0 + 9388);
    t165 = *((char **)t164);
    t166 = ((((char*)(t165))) + 20U);
    t167 = *((char **)t166);
    t166 = (t0 + 9408);
    t168 = *((char **)t166);
    t169 = ((((char*)(t168))) + 20U);
    t170 = *((char **)t169);
    t169 = (t0 + 9428);
    t171 = *((char **)t169);
    t172 = ((((char*)(t171))) + 20U);
    t173 = *((char **)t172);
    xsi_vlogfile_write(1, 0, ng35, 5, t0, (char)119, t163, 32, (char)118, t167, 2, (char)118, t170, 2, (char)118, t173, 2);
    goto LAB48;

}

static void A199_12(char *t0)
{
    char t3[8];
    char t14[8];
    char t30[8];
    char t37[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    int t61;
    int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;

LAB0:    t1 = (t0 + 4996U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(199, ng0);
    t2 = (t0 + 5752);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(199, ng0);

LAB5:    xsi_set_current_line(200, ng0);
    t4 = (t0 + 1512);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t3 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t8) == 0)
        goto LAB6;

LAB8:    *((unsigned int *)t3) = 1;
    *((unsigned int *)t7) = 1;

LAB9:    memset(t14, 0, 8);
    t15 = (t14 + 4U);
    t16 = (t3 + 4U);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t3);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t16) != 0)
        goto LAB12;

LAB13:    t22 = (t14 + 4U);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t22);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB14;

LAB15:    memcpy(t37, t14, 8);

LAB16:    t69 = (t37 + 4U);
    t70 = *((unsigned int *)t69);
    t71 = (~(t70));
    t72 = *((unsigned int *)t37);
    t73 = (t72 & t71);
    t74 = (t73 != 0);
    if (t74 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t14) = 1;
    goto LAB13;

LAB12:    *((unsigned int *)t14) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB13;

LAB14:    t26 = (t0 + 9452);
    t27 = *((char **)t26);
    t28 = ((((char*)(t27))) + 20U);
    t29 = *((char **)t28);
    memset(t30, 0, 8);
    t28 = (t30 + 4U);
    t31 = (t29 + 4U);
    t32 = *((unsigned int *)t31);
    t33 = (~(t32));
    t34 = *((unsigned int *)t29);
    t35 = (t34 & t33);
    t36 = (t35 & 1U);
    if (t36 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t31) != 0)
        goto LAB19;

LAB20:    t38 = *((unsigned int *)t14);
    t39 = *((unsigned int *)t30);
    t40 = (t38 & t39);
    *((unsigned int *)t37) = t40;
    t41 = (t14 + 4U);
    t42 = (t30 + 4U);
    t43 = (t37 + 4U);
    t44 = *((unsigned int *)t41);
    t45 = *((unsigned int *)t42);
    t46 = (t44 | t45);
    *((unsigned int *)t43) = t46;
    t47 = *((unsigned int *)t43);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t30) = 1;
    goto LAB20;

LAB19:    *((unsigned int *)t30) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB20;

LAB21:    t49 = *((unsigned int *)t37);
    t50 = *((unsigned int *)t43);
    *((unsigned int *)t37) = (t49 | t50);
    t51 = (t14 + 4U);
    t52 = (t30 + 4U);
    t53 = *((unsigned int *)t14);
    t54 = (~(t53));
    t55 = *((unsigned int *)t51);
    t56 = (~(t55));
    t57 = *((unsigned int *)t30);
    t58 = (~(t57));
    t59 = *((unsigned int *)t52);
    t60 = (~(t59));
    t61 = (t54 & t56);
    t62 = (t58 & t60);
    t63 = (~(t61));
    t64 = (~(t62));
    t65 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t65 & t63);
    t66 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t66 & t64);
    t67 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t67 & t63);
    t68 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t68 & t64);
    goto LAB23;

LAB24:    xsi_set_current_line(201, ng0);
    t75 = (t0 + 1604);
    t76 = (t75 + 32U);
    t77 = *((char **)t76);
    t78 = (t0 + 9480);
    t79 = *((char **)t78);
    t80 = ((((char*)(t79))) + 20U);
    t81 = *((char **)t80);
    t80 = (t0 + 9504);
    t82 = *((char **)t80);
    t83 = ((((char*)(t82))) + 20U);
    t84 = *((char **)t83);
    t83 = (t0 + 9528);
    t85 = *((char **)t83);
    t86 = ((((char*)(t85))) + 20U);
    t87 = *((char **)t86);
    xsi_vlogfile_write(1, 0, ng36, 5, t0, (char)119, t77, 32, (char)118, t81, 2, (char)118, t84, 32, (char)118, t87, 32);
    goto LAB26;

}

static void A207_13(char *t0)
{
    char t3[8];
    char t14[8];
    char t30[8];
    char t37[8];
    char t88[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    int t61;
    int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t89;
    char *t90;
    char *t91;
    char *t92;
    char *t93;
    char *t94;
    char *t95;

LAB0:    t1 = (t0 + 5124U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(207, ng0);
    t2 = (t0 + 5760);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(207, ng0);

LAB5:    xsi_set_current_line(208, ng0);
    t4 = (t0 + 1512);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t3 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t8) == 0)
        goto LAB6;

LAB8:    *((unsigned int *)t3) = 1;
    *((unsigned int *)t7) = 1;

LAB9:    memset(t14, 0, 8);
    t15 = (t14 + 4U);
    t16 = (t3 + 4U);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t3);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t16) != 0)
        goto LAB12;

LAB13:    t22 = (t14 + 4U);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t22);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB14;

LAB15:    memcpy(t37, t14, 8);

LAB16:    t69 = (t37 + 4U);
    t70 = *((unsigned int *)t69);
    t71 = (~(t70));
    t72 = *((unsigned int *)t37);
    t73 = (t72 & t71);
    t74 = (t73 != 0);
    if (t74 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t14) = 1;
    goto LAB13;

LAB12:    *((unsigned int *)t14) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB13;

LAB14:    t26 = (t0 + 9552);
    t27 = *((char **)t26);
    t28 = ((((char*)(t27))) + 20U);
    t29 = *((char **)t28);
    memset(t30, 0, 8);
    t28 = (t30 + 4U);
    t31 = (t29 + 4U);
    t32 = *((unsigned int *)t31);
    t33 = (~(t32));
    t34 = *((unsigned int *)t29);
    t35 = (t34 & t33);
    t36 = (t35 & 1U);
    if (t36 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t31) != 0)
        goto LAB19;

LAB20:    t38 = *((unsigned int *)t14);
    t39 = *((unsigned int *)t30);
    t40 = (t38 & t39);
    *((unsigned int *)t37) = t40;
    t41 = (t14 + 4U);
    t42 = (t30 + 4U);
    t43 = (t37 + 4U);
    t44 = *((unsigned int *)t41);
    t45 = *((unsigned int *)t42);
    t46 = (t44 | t45);
    *((unsigned int *)t43) = t46;
    t47 = *((unsigned int *)t43);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t30) = 1;
    goto LAB20;

LAB19:    *((unsigned int *)t30) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB20;

LAB21:    t49 = *((unsigned int *)t37);
    t50 = *((unsigned int *)t43);
    *((unsigned int *)t37) = (t49 | t50);
    t51 = (t14 + 4U);
    t52 = (t30 + 4U);
    t53 = *((unsigned int *)t14);
    t54 = (~(t53));
    t55 = *((unsigned int *)t51);
    t56 = (~(t55));
    t57 = *((unsigned int *)t30);
    t58 = (~(t57));
    t59 = *((unsigned int *)t52);
    t60 = (~(t59));
    t61 = (t54 & t56);
    t62 = (t58 & t60);
    t63 = (~(t61));
    t64 = (~(t62));
    t65 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t65 & t63);
    t66 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t66 & t64);
    t67 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t67 & t63);
    t68 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t68 & t64);
    goto LAB23;

LAB24:    xsi_set_current_line(209, ng0);
    t75 = (t0 + 1604);
    t76 = (t75 + 32U);
    t77 = *((char **)t76);
    t78 = (t0 + 9576);
    t79 = *((char **)t78);
    t80 = ((((char*)(t79))) + 20U);
    t81 = *((char **)t80);
    t80 = (t0 + 9596);
    t82 = *((char **)t80);
    t83 = ((((char*)(t82))) + 20U);
    t84 = *((char **)t83);
    t83 = (t0 + 9616);
    t85 = *((char **)t83);
    t86 = ((((char*)(t85))) + 20U);
    t87 = *((char **)t86);
    t86 = ((char*)((ng16)));
    memset(t88, 0, 8);
    xsi_vlog_unsigned_rshift(t88, 32, t87, 32, t86, 32);
    t89 = (t0 + 9636);
    t90 = *((char **)t89);
    t91 = ((((char*)(t90))) + 20U);
    t92 = *((char **)t91);
    t91 = (t0 + 9656);
    t93 = *((char **)t91);
    t94 = ((((char*)(t93))) + 20U);
    t95 = *((char **)t94);
    xsi_vlogfile_write(1, 0, ng37, 7, t0, (char)119, t77, 32, (char)118, t81, 2, (char)118, t84, 32, (char)118, t88, 32, (char)118, t92, 32, (char)118, t95, 32);
    goto LAB26;

}

static void A216_14(char *t0)
{
    char t3[8];
    char t14[8];
    char t30[8];
    char t37[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    int t61;
    int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;

LAB0:    t1 = (t0 + 5252U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(216, ng0);
    t2 = (t0 + 5768);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(216, ng0);

LAB5:    xsi_set_current_line(217, ng0);
    t4 = (t0 + 1512);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t3 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t8) == 0)
        goto LAB6;

LAB8:    *((unsigned int *)t3) = 1;
    *((unsigned int *)t7) = 1;

LAB9:    memset(t14, 0, 8);
    t15 = (t14 + 4U);
    t16 = (t3 + 4U);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t3);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t16) != 0)
        goto LAB12;

LAB13:    t22 = (t14 + 4U);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t22);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB14;

LAB15:    memcpy(t37, t14, 8);

LAB16:    t69 = (t37 + 4U);
    t70 = *((unsigned int *)t69);
    t71 = (~(t70));
    t72 = *((unsigned int *)t37);
    t73 = (t72 & t71);
    t74 = (t73 != 0);
    if (t74 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t14) = 1;
    goto LAB13;

LAB12:    *((unsigned int *)t14) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB13;

LAB14:    t26 = (t0 + 9680);
    t27 = *((char **)t26);
    t28 = ((((char*)(t27))) + 20U);
    t29 = *((char **)t28);
    memset(t30, 0, 8);
    t28 = (t30 + 4U);
    t31 = (t29 + 4U);
    t32 = *((unsigned int *)t31);
    t33 = (~(t32));
    t34 = *((unsigned int *)t29);
    t35 = (t34 & t33);
    t36 = (t35 & 1U);
    if (t36 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t31) != 0)
        goto LAB19;

LAB20:    t38 = *((unsigned int *)t14);
    t39 = *((unsigned int *)t30);
    t40 = (t38 & t39);
    *((unsigned int *)t37) = t40;
    t41 = (t14 + 4U);
    t42 = (t30 + 4U);
    t43 = (t37 + 4U);
    t44 = *((unsigned int *)t41);
    t45 = *((unsigned int *)t42);
    t46 = (t44 | t45);
    *((unsigned int *)t43) = t46;
    t47 = *((unsigned int *)t43);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t30) = 1;
    goto LAB20;

LAB19:    *((unsigned int *)t30) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB20;

LAB21:    t49 = *((unsigned int *)t37);
    t50 = *((unsigned int *)t43);
    *((unsigned int *)t37) = (t49 | t50);
    t51 = (t14 + 4U);
    t52 = (t30 + 4U);
    t53 = *((unsigned int *)t14);
    t54 = (~(t53));
    t55 = *((unsigned int *)t51);
    t56 = (~(t55));
    t57 = *((unsigned int *)t30);
    t58 = (~(t57));
    t59 = *((unsigned int *)t52);
    t60 = (~(t59));
    t61 = (t54 & t56);
    t62 = (t58 & t60);
    t63 = (~(t61));
    t64 = (~(t62));
    t65 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t65 & t63);
    t66 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t66 & t64);
    t67 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t67 & t63);
    t68 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t68 & t64);
    goto LAB23;

LAB24:    xsi_set_current_line(218, ng0);
    t75 = (t0 + 1604);
    t76 = (t75 + 32U);
    t77 = *((char **)t76);
    t78 = (t0 + 9704);
    t79 = *((char **)t78);
    t80 = ((((char*)(t79))) + 20U);
    t81 = *((char **)t80);
    t80 = (t0 + 9724);
    t82 = *((char **)t80);
    t83 = ((((char*)(t82))) + 20U);
    t84 = *((char **)t83);
    xsi_vlogfile_write(1, 0, ng38, 4, t0, (char)119, t77, 32, (char)118, t81, 2, (char)118, t84, 32);
    goto LAB26;

}

static void A223_15(char *t0)
{
    char t3[8];
    char t14[8];
    char t30[8];
    char t37[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    int t61;
    int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    char *t89;
    char *t90;
    char *t91;
    char *t92;
    char *t93;

LAB0:    t1 = (t0 + 5380U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(223, ng0);
    t2 = (t0 + 5776);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(223, ng0);

LAB5:    xsi_set_current_line(224, ng0);
    t4 = (t0 + 1512);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t3 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t8) == 0)
        goto LAB6;

LAB8:    *((unsigned int *)t3) = 1;
    *((unsigned int *)t7) = 1;

LAB9:    memset(t14, 0, 8);
    t15 = (t14 + 4U);
    t16 = (t3 + 4U);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t3);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t16) != 0)
        goto LAB12;

LAB13:    t22 = (t14 + 4U);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t22);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB14;

LAB15:    memcpy(t37, t14, 8);

LAB16:    t69 = (t37 + 4U);
    t70 = *((unsigned int *)t69);
    t71 = (~(t70));
    t72 = *((unsigned int *)t37);
    t73 = (t72 & t71);
    t74 = (t73 != 0);
    if (t74 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t14) = 1;
    goto LAB13;

LAB12:    *((unsigned int *)t14) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB13;

LAB14:    t26 = (t0 + 9748);
    t27 = *((char **)t26);
    t28 = ((((char*)(t27))) + 20U);
    t29 = *((char **)t28);
    memset(t30, 0, 8);
    t28 = (t30 + 4U);
    t31 = (t29 + 4U);
    t32 = *((unsigned int *)t31);
    t33 = (~(t32));
    t34 = *((unsigned int *)t29);
    t35 = (t34 & t33);
    t36 = (t35 & 1U);
    if (t36 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t31) != 0)
        goto LAB19;

LAB20:    t38 = *((unsigned int *)t14);
    t39 = *((unsigned int *)t30);
    t40 = (t38 & t39);
    *((unsigned int *)t37) = t40;
    t41 = (t14 + 4U);
    t42 = (t30 + 4U);
    t43 = (t37 + 4U);
    t44 = *((unsigned int *)t41);
    t45 = *((unsigned int *)t42);
    t46 = (t44 | t45);
    *((unsigned int *)t43) = t46;
    t47 = *((unsigned int *)t43);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t30) = 1;
    goto LAB20;

LAB19:    *((unsigned int *)t30) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB20;

LAB21:    t49 = *((unsigned int *)t37);
    t50 = *((unsigned int *)t43);
    *((unsigned int *)t37) = (t49 | t50);
    t51 = (t14 + 4U);
    t52 = (t30 + 4U);
    t53 = *((unsigned int *)t14);
    t54 = (~(t53));
    t55 = *((unsigned int *)t51);
    t56 = (~(t55));
    t57 = *((unsigned int *)t30);
    t58 = (~(t57));
    t59 = *((unsigned int *)t52);
    t60 = (~(t59));
    t61 = (t54 & t56);
    t62 = (t58 & t60);
    t63 = (~(t61));
    t64 = (~(t62));
    t65 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t65 & t63);
    t66 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t66 & t64);
    t67 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t67 & t63);
    t68 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t68 & t64);
    goto LAB23;

LAB24:    xsi_set_current_line(225, ng0);
    t75 = (t0 + 1604);
    t76 = (t75 + 32U);
    t77 = *((char **)t76);
    t78 = (t0 + 9772);
    t79 = *((char **)t78);
    t80 = ((((char*)(t79))) + 20U);
    t81 = *((char **)t80);
    t80 = (t0 + 9788);
    t82 = *((char **)t80);
    t83 = ((((char*)(t82))) + 20U);
    t84 = *((char **)t83);
    t83 = (t0 + 9804);
    t85 = *((char **)t83);
    t86 = ((((char*)(t85))) + 20U);
    t87 = *((char **)t86);
    t86 = (t0 + 9820);
    t88 = *((char **)t86);
    t89 = ((((char*)(t88))) + 20U);
    t90 = *((char **)t89);
    t89 = (t0 + 9836);
    t91 = *((char **)t89);
    t92 = ((((char*)(t91))) + 20U);
    t93 = *((char **)t92);
    xsi_vlogfile_write(1, 0, ng39, 7, t0, (char)119, t77, 32, (char)118, t81, 2, (char)118, t84, 1, (char)118, t87, 1, (char)118, t90, 1, (char)118, t93, 1);
    goto LAB26;

}

static void I233_16(char *t0)
{
    char t22[8];
    char t23[40];
    char t24[8];
    char t26[8];
    char t37[8];
    char t67[48];
    char t69[8];
    char t70[8];
    char t75[8];
    char t78[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t25;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t38;
    char *t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    char *t50;
    char *t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    char *t68;
    char *t71;
    char *t72;
    char *t73;
    char *t74;
    char *t76;
    char *t77;
    char *t79;
    char *t80;
    char *t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    char *t87;
    char *t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    char *t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    char *t106;
    char *t107;
    char *t108;
    char *t109;
    char *t110;
    char *t111;

LAB0:    t1 = (t0 + 5508U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(233, ng0);

LAB4:    xsi_set_current_line(234, ng0);
    xsi_vcd_dumpfile(ng40);
    xsi_set_current_line(235, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5424);
    xsi_vcd_dumpvars_args(*((unsigned int *)t2), t3, (char)109, t0, (char)101);
    xsi_set_current_line(237, ng0);
    t2 = (t0 + 5424);
    t3 = (t0 + 456);
    t4 = xsi_create_subprogram_invocation(t2, 0, t0, t3, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t3, t4);

LAB6:    t5 = (t0 + 5472);
    t6 = *((char **)t5);
    t7 = (t6 + 40U);
    t8 = *((char **)t7);
    t9 = (t8 + 132U);
    t10 = *((char **)t9);
    t11 = (t10 + 0U);
    t12 = *((char **)t11);
    t13 = ((int  (*)(char *, char *))t12)(t0, t6);
    if (t13 != 0)
        goto LAB8;

LAB7:    t6 = (t0 + 456);
    xsi_vlog_subprogram_popinvocation(t6);

LAB5:    t14 = (t0 + 5472);
    t15 = *((char **)t14);
    t14 = (t0 + 456);
    t16 = (t0 + 5472);
    t17 = *((char **)t16);
    t16 = (t0 + 5424);
    t18 = 0;
    xsi_delete_subprogram_invocation(t14, t17, t0, t16, t18);
    xsi_set_current_line(242, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 1512);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(243, ng0);
    t2 = ((char*)((ng41)));
    t3 = (t2 + 4U);
    t19 = *((unsigned int *)t3);
    t20 = (~(t19));
    t21 = *((unsigned int *)t2);
    t13 = (t21 & t20);
    t4 = (t0 + 9840);
    *((int *)t4) = t13;

LAB9:    t5 = (t0 + 9840);
    if (*((int *)t5) > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(244, ng0);
    t2 = (t0 + 5424);
    xsi_process_wait(t2, 1000000LL);
    *((char **)t1) = &&LAB13;

LAB1:    return;
LAB8:    t5 = (t0 + 5508U);
    *((char **)t5) = &&LAB6;
    goto LAB1;

LAB10:    xsi_set_current_line(243, ng0);
    t6 = (t0 + 5784);
    *((int *)t6) = 1;
    *((char **)t1) = &&LAB12;
    goto LAB1;

LAB12:    t2 = (t0 + 9840);
    t13 = *((int *)t2);
    *((int *)t2) = (t13 - 1);
    goto LAB9;

LAB13:    xsi_set_current_line(244, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t0 + 1512);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(246, ng0);
    xsi_vlogfile_write(1, 0, ng42, 1, t0);
    xsi_set_current_line(247, ng0);
    xsi_vlogfile_write(1, 0, ng43, 1, t0);
    xsi_set_current_line(248, ng0);
    xsi_vlogfile_write(1, 0, ng44, 1, t0);
    xsi_set_current_line(249, ng0);
    xsi_vlogfile_write(1, 0, ng45, 1, t0);
    xsi_set_current_line(250, ng0);
    xsi_vlogfile_write(1, 0, ng43, 1, t0);
    xsi_set_current_line(255, ng0);
    t2 = (t0 + 5424);
    xsi_process_wait(t2, 1000000LL);
    *((char **)t1) = &&LAB14;
    goto LAB1;

LAB14:    xsi_set_current_line(256, ng0);
    t2 = (t0 + 5792);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB15:    xsi_set_current_line(257, ng0);
    xsi_vlogfile_write(1, 0, ng42, 1, t0);
    xsi_set_current_line(258, ng0);
    xsi_vlogfile_write(1, 0, ng46, 1, t0);
    xsi_set_current_line(259, ng0);
    t2 = (t0 + 9852);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 9864);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = (t0 + 9876);
    t11 = *((char **)t10);
    t12 = ((((char*)(t11))) + 36U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng1)));
    xsi_vlog_generic_get_array_select_value(t22, 32, t5, t9, t14, 2, 1, t15, 32, 1);
    t16 = (t0 + 9888);
    t17 = *((char **)t16);
    t18 = ((((char*)(t17))) + 32U);
    t25 = *((char **)t18);
    t27 = (t0 + 9900);
    t28 = *((char **)t27);
    t29 = ((((char*)(t28))) + 40U);
    t30 = *((char **)t29);
    t31 = (t0 + 9912);
    t32 = *((char **)t31);
    t33 = ((((char*)(t32))) + 36U);
    t34 = *((char **)t33);
    t35 = ((char*)((ng1)));
    xsi_vlog_generic_get_array_select_value(t26, 32, t25, t30, t34, 2, 1, t35, 32, 1);
    t36 = ((char*)((ng1)));
    memset(t37, 0, 8);
    t38 = (t37 + 4U);
    t39 = (t26 + 4U);
    t40 = (t36 + 4U);
    t19 = *((unsigned int *)t26);
    t20 = *((unsigned int *)t36);
    t21 = (t19 ^ t20);
    t41 = *((unsigned int *)t39);
    t42 = *((unsigned int *)t40);
    t43 = (t41 ^ t42);
    t44 = (t21 | t43);
    t45 = *((unsigned int *)t39);
    t46 = *((unsigned int *)t40);
    t47 = (t45 | t46);
    t48 = (~(t47));
    t49 = (t44 & t48);
    if (t49 != 0)
        goto LAB19;

LAB16:    if (t47 != 0)
        goto LAB18;

LAB17:    *((unsigned int *)t37) = 1;

LAB19:    memset(t24, 0, 8);
    t50 = (t24 + 4U);
    t51 = (t37 + 4U);
    t52 = *((unsigned int *)t51);
    t53 = (~(t52));
    t54 = *((unsigned int *)t37);
    t55 = (t54 & t53);
    t56 = (t55 & 1U);
    if (t56 != 0)
        goto LAB20;

LAB21:    if (*((unsigned int *)t51) != 0)
        goto LAB22;

LAB23:    t57 = (t24 + 4U);
    t58 = *((unsigned int *)t24);
    t59 = *((unsigned int *)t57);
    t60 = (t58 || t59);
    if (t60 > 0)
        goto LAB24;

LAB25:    t62 = *((unsigned int *)t24);
    t63 = (~(t62));
    t64 = *((unsigned int *)t57);
    t65 = (t63 || t64);
    if (t65 > 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t57) > 0)
        goto LAB28;

LAB29:    if (*((unsigned int *)t24) > 0)
        goto LAB30;

LAB31:    memcpy(t23, t66, 40);

LAB32:    xsi_vlogfile_write(1, 0, ng47, 3, t0, (char)118, t22, 32, (char)118, t23, 152);
    xsi_set_current_line(261, ng0);
    t2 = (t0 + 9924);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 9936);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = (t0 + 9948);
    t11 = *((char **)t10);
    t12 = ((((char*)(t11))) + 36U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng6)));
    xsi_vlog_generic_get_array_select_value(t22, 32, t5, t9, t14, 2, 1, t15, 32, 1);
    t16 = (t0 + 9960);
    t17 = *((char **)t16);
    t18 = ((((char*)(t17))) + 32U);
    t25 = *((char **)t18);
    t27 = (t0 + 9972);
    t28 = *((char **)t27);
    t29 = ((((char*)(t28))) + 40U);
    t30 = *((char **)t29);
    t31 = (t0 + 9984);
    t32 = *((char **)t31);
    t33 = ((((char*)(t32))) + 36U);
    t34 = *((char **)t33);
    t35 = ((char*)((ng6)));
    xsi_vlog_generic_get_array_select_value(t26, 32, t25, t30, t34, 2, 1, t35, 32, 1);
    t36 = ((char*)((ng51)));
    memset(t37, 0, 8);
    t38 = (t37 + 4U);
    t39 = (t26 + 4U);
    t40 = (t36 + 4U);
    t19 = *((unsigned int *)t26);
    t20 = *((unsigned int *)t36);
    t21 = (t19 ^ t20);
    t41 = *((unsigned int *)t39);
    t42 = *((unsigned int *)t40);
    t43 = (t41 ^ t42);
    t44 = (t21 | t43);
    t45 = *((unsigned int *)t39);
    t46 = *((unsigned int *)t40);
    t47 = (t45 | t46);
    t48 = (~(t47));
    t49 = (t44 & t48);
    if (t49 != 0)
        goto LAB36;

LAB33:    if (t47 != 0)
        goto LAB35;

LAB34:    *((unsigned int *)t37) = 1;

LAB36:    memset(t24, 0, 8);
    t50 = (t24 + 4U);
    t51 = (t37 + 4U);
    t52 = *((unsigned int *)t51);
    t53 = (~(t52));
    t54 = *((unsigned int *)t37);
    t55 = (t54 & t53);
    t56 = (t55 & 1U);
    if (t56 != 0)
        goto LAB37;

LAB38:    if (*((unsigned int *)t51) != 0)
        goto LAB39;

LAB40:    t57 = (t24 + 4U);
    t58 = *((unsigned int *)t24);
    t59 = *((unsigned int *)t57);
    t60 = (t58 || t59);
    if (t60 > 0)
        goto LAB41;

LAB42:    t62 = *((unsigned int *)t24);
    t63 = (~(t62));
    t64 = *((unsigned int *)t57);
    t65 = (t63 || t64);
    if (t65 > 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t57) > 0)
        goto LAB45;

LAB46:    if (*((unsigned int *)t24) > 0)
        goto LAB47;

LAB48:    memcpy(t23, t66, 40);

LAB49:    xsi_vlogfile_write(1, 0, ng50, 3, t0, (char)118, t22, 32, (char)118, t23, 160);
    xsi_set_current_line(263, ng0);
    t2 = (t0 + 9996);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 10008);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = (t0 + 10020);
    t11 = *((char **)t10);
    t12 = ((((char*)(t11))) + 36U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng16)));
    xsi_vlog_generic_get_array_select_value(t22, 32, t5, t9, t14, 2, 1, t15, 32, 1);
    t16 = (t0 + 10032);
    t17 = *((char **)t16);
    t18 = ((((char*)(t17))) + 32U);
    t25 = *((char **)t18);
    t27 = (t0 + 10044);
    t28 = *((char **)t27);
    t29 = ((((char*)(t28))) + 40U);
    t30 = *((char **)t29);
    t31 = (t0 + 10056);
    t32 = *((char **)t31);
    t33 = ((((char*)(t32))) + 36U);
    t34 = *((char **)t33);
    t35 = ((char*)((ng16)));
    xsi_vlog_generic_get_array_select_value(t26, 32, t25, t30, t34, 2, 1, t35, 32, 1);
    t36 = ((char*)((ng54)));
    memset(t37, 0, 8);
    t38 = (t37 + 4U);
    t39 = (t26 + 4U);
    t40 = (t36 + 4U);
    t19 = *((unsigned int *)t26);
    t20 = *((unsigned int *)t36);
    t21 = (t19 ^ t20);
    t41 = *((unsigned int *)t39);
    t42 = *((unsigned int *)t40);
    t43 = (t41 ^ t42);
    t44 = (t21 | t43);
    t45 = *((unsigned int *)t39);
    t46 = *((unsigned int *)t40);
    t47 = (t45 | t46);
    t48 = (~(t47));
    t49 = (t44 & t48);
    if (t49 != 0)
        goto LAB53;

LAB50:    if (t47 != 0)
        goto LAB52;

LAB51:    *((unsigned int *)t37) = 1;

LAB53:    memset(t24, 0, 8);
    t50 = (t24 + 4U);
    t51 = (t37 + 4U);
    t52 = *((unsigned int *)t51);
    t53 = (~(t52));
    t54 = *((unsigned int *)t37);
    t55 = (t54 & t53);
    t56 = (t55 & 1U);
    if (t56 != 0)
        goto LAB54;

LAB55:    if (*((unsigned int *)t51) != 0)
        goto LAB56;

LAB57:    t57 = (t24 + 4U);
    t58 = *((unsigned int *)t24);
    t59 = *((unsigned int *)t57);
    t60 = (t58 || t59);
    if (t60 > 0)
        goto LAB58;

LAB59:    t62 = *((unsigned int *)t24);
    t63 = (~(t62));
    t64 = *((unsigned int *)t57);
    t65 = (t63 || t64);
    if (t65 > 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t57) > 0)
        goto LAB62;

LAB63:    if (*((unsigned int *)t24) > 0)
        goto LAB64;

LAB65:    memcpy(t67, t66, 48);

LAB66:    xsi_vlogfile_write(1, 0, ng53, 3, t0, (char)118, t22, 32, (char)118, t67, 168);
    xsi_set_current_line(265, ng0);
    t2 = (t0 + 10068);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 10080);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = (t0 + 10092);
    t11 = *((char **)t10);
    t12 = ((((char*)(t11))) + 36U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng18)));
    xsi_vlog_generic_get_array_select_value(t22, 32, t5, t9, t14, 2, 1, t15, 32, 1);
    t16 = (t0 + 10104);
    t17 = *((char **)t16);
    t18 = ((((char*)(t17))) + 32U);
    t25 = *((char **)t18);
    t27 = (t0 + 10116);
    t28 = *((char **)t27);
    t29 = ((((char*)(t28))) + 40U);
    t30 = *((char **)t29);
    t31 = (t0 + 10128);
    t32 = *((char **)t31);
    t33 = ((((char*)(t32))) + 36U);
    t34 = *((char **)t33);
    t35 = ((char*)((ng18)));
    xsi_vlog_generic_get_array_select_value(t26, 32, t25, t30, t34, 2, 1, t35, 32, 1);
    t36 = ((char*)((ng58)));
    memset(t37, 0, 8);
    t38 = (t37 + 4U);
    t39 = (t26 + 4U);
    t40 = (t36 + 4U);
    t19 = *((unsigned int *)t26);
    t20 = *((unsigned int *)t36);
    t21 = (t19 ^ t20);
    t41 = *((unsigned int *)t39);
    t42 = *((unsigned int *)t40);
    t43 = (t41 ^ t42);
    t44 = (t21 | t43);
    t45 = *((unsigned int *)t39);
    t46 = *((unsigned int *)t40);
    t47 = (t45 | t46);
    t48 = (~(t47));
    t49 = (t44 & t48);
    if (t49 != 0)
        goto LAB70;

LAB67:    if (t47 != 0)
        goto LAB69;

LAB68:    *((unsigned int *)t37) = 1;

LAB70:    memset(t24, 0, 8);
    t50 = (t24 + 4U);
    t51 = (t37 + 4U);
    t52 = *((unsigned int *)t51);
    t53 = (~(t52));
    t54 = *((unsigned int *)t37);
    t55 = (t54 & t53);
    t56 = (t55 & 1U);
    if (t56 != 0)
        goto LAB71;

LAB72:    if (*((unsigned int *)t51) != 0)
        goto LAB73;

LAB74:    t57 = (t24 + 4U);
    t58 = *((unsigned int *)t24);
    t59 = *((unsigned int *)t57);
    t60 = (t58 || t59);
    if (t60 > 0)
        goto LAB75;

LAB76:    t62 = *((unsigned int *)t24);
    t63 = (~(t62));
    t64 = *((unsigned int *)t57);
    t65 = (t63 || t64);
    if (t65 > 0)
        goto LAB77;

LAB78:    if (*((unsigned int *)t57) > 0)
        goto LAB79;

LAB80:    if (*((unsigned int *)t24) > 0)
        goto LAB81;

LAB82:    memcpy(t67, t66, 48);

LAB83:    xsi_vlogfile_write(1, 0, ng57, 3, t0, (char)118, t22, 32, (char)118, t67, 168);
    xsi_set_current_line(271, ng0);
    t2 = ((char*)((ng60)));
    t3 = (t2 + 4U);
    t19 = *((unsigned int *)t3);
    t20 = (~(t19));
    t21 = *((unsigned int *)t2);
    t13 = (t21 & t20);
    t4 = (t0 + 10132);
    *((int *)t4) = t13;

LAB84:    t5 = (t0 + 10132);
    if (*((int *)t5) > 0)
        goto LAB85;

LAB86:    xsi_set_current_line(272, ng0);
    t2 = (t0 + 5424);
    t3 = (t0 + 936);
    t4 = xsi_create_subprogram_invocation(t2, 0, t0, t3, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t3, t4);

LAB89:    t5 = (t0 + 5472);
    t6 = *((char **)t5);
    t7 = (t6 + 40U);
    t8 = *((char **)t7);
    t9 = (t8 + 132U);
    t10 = *((char **)t9);
    t11 = (t10 + 0U);
    t12 = *((char **)t11);
    t13 = ((int  (*)(char *, char *))t12)(t0, t6);
    if (t13 != 0)
        goto LAB91;

LAB90:    t6 = (t0 + 936);
    xsi_vlog_subprogram_popinvocation(t6);

LAB88:    t14 = (t0 + 5472);
    t15 = *((char **)t14);
    t14 = (t0 + 936);
    t16 = (t0 + 5472);
    t17 = *((char **)t16);
    t16 = (t0 + 5424);
    t18 = 0;
    xsi_delete_subprogram_invocation(t14, t17, t0, t16, t18);
    xsi_set_current_line(283, ng0);
    t2 = ((char*)((ng61)));
    t3 = (t2 + 4U);
    t19 = *((unsigned int *)t3);
    t20 = (~(t19));
    t21 = *((unsigned int *)t2);
    t13 = (t21 & t20);
    t4 = (t0 + 10136);
    *((int *)t4) = t13;

LAB92:    t5 = (t0 + 10136);
    if (*((int *)t5) > 0)
        goto LAB93;

LAB94:    xsi_set_current_line(288, ng0);
    xsi_vlogfile_write(1, 0, ng42, 1, t0);
    xsi_set_current_line(289, ng0);
    xsi_vlogfile_write(1, 0, ng62, 1, t0);
    xsi_set_current_line(290, ng0);
    t2 = (t0 + 10156);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 10176);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = ((char*)((ng1)));
    xsi_vlog_generic_get_index_select_value(t22, 1, t5, t9, 2, t10, 32, 1);
    t11 = (t0 + 10196);
    t12 = *((char **)t11);
    t14 = ((((char*)(t12))) + 32U);
    t15 = *((char **)t14);
    t16 = (t0 + 10216);
    t17 = *((char **)t16);
    t18 = ((((char*)(t17))) + 40U);
    t25 = *((char **)t18);
    t27 = ((char*)((ng1)));
    xsi_vlog_generic_get_index_select_value(t24, 1, t15, t25, 2, t27, 32, 1);
    t28 = (t0 + 10236);
    t29 = *((char **)t28);
    t30 = ((((char*)(t29))) + 32U);
    t31 = *((char **)t30);
    t32 = (t0 + 10256);
    t33 = *((char **)t32);
    t34 = ((((char*)(t33))) + 40U);
    t35 = *((char **)t34);
    t36 = ((char*)((ng1)));
    xsi_vlog_generic_get_index_select_value(t26, 1, t31, t35, 2, t36, 32, 1);
    t38 = (t0 + 10276);
    t39 = *((char **)t38);
    t40 = ((((char*)(t39))) + 32U);
    t50 = *((char **)t40);
    t51 = (t0 + 10296);
    t57 = *((char **)t51);
    t61 = ((((char*)(t57))) + 40U);
    t66 = *((char **)t61);
    t68 = ((char*)((ng1)));
    xsi_vlog_generic_get_index_select_value(t37, 1, t50, t66, 2, t68, 32, 1);
    xsi_vlogfile_write(1, 0, ng63, 5, t0, (char)118, t22, 1, (char)118, t24, 1, (char)118, t26, 1, (char)118, t37, 1);
    xsi_set_current_line(293, ng0);
    t2 = (t0 + 10316);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 10336);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = ((char*)((ng6)));
    xsi_vlog_generic_get_index_select_value(t22, 1, t5, t9, 2, t10, 32, 1);
    t11 = (t0 + 10356);
    t12 = *((char **)t11);
    t14 = ((((char*)(t12))) + 32U);
    t15 = *((char **)t14);
    t16 = (t0 + 10376);
    t17 = *((char **)t16);
    t18 = ((((char*)(t17))) + 40U);
    t25 = *((char **)t18);
    t27 = ((char*)((ng6)));
    xsi_vlog_generic_get_index_select_value(t24, 1, t15, t25, 2, t27, 32, 1);
    t28 = (t0 + 10396);
    t29 = *((char **)t28);
    t30 = ((((char*)(t29))) + 32U);
    t31 = *((char **)t30);
    t32 = (t0 + 10416);
    t33 = *((char **)t32);
    t34 = ((((char*)(t33))) + 40U);
    t35 = *((char **)t34);
    t36 = ((char*)((ng6)));
    xsi_vlog_generic_get_index_select_value(t26, 1, t31, t35, 2, t36, 32, 1);
    t38 = (t0 + 10436);
    t39 = *((char **)t38);
    t40 = ((((char*)(t39))) + 32U);
    t50 = *((char **)t40);
    t51 = (t0 + 10456);
    t57 = *((char **)t51);
    t61 = ((((char*)(t57))) + 40U);
    t66 = *((char **)t61);
    t68 = ((char*)((ng6)));
    xsi_vlog_generic_get_index_select_value(t37, 1, t50, t66, 2, t68, 32, 1);
    xsi_vlogfile_write(1, 0, ng64, 5, t0, (char)118, t22, 1, (char)118, t24, 1, (char)118, t26, 1, (char)118, t37, 1);
    xsi_set_current_line(296, ng0);
    t2 = (t0 + 10476);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 10496);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = ((char*)((ng16)));
    xsi_vlog_generic_get_index_select_value(t22, 1, t5, t9, 2, t10, 32, 1);
    t11 = (t0 + 10516);
    t12 = *((char **)t11);
    t14 = ((((char*)(t12))) + 32U);
    t15 = *((char **)t14);
    t16 = (t0 + 10536);
    t17 = *((char **)t16);
    t18 = ((((char*)(t17))) + 40U);
    t25 = *((char **)t18);
    t27 = ((char*)((ng16)));
    xsi_vlog_generic_get_index_select_value(t24, 1, t15, t25, 2, t27, 32, 1);
    t28 = (t0 + 10556);
    t29 = *((char **)t28);
    t30 = ((((char*)(t29))) + 32U);
    t31 = *((char **)t30);
    t32 = (t0 + 10576);
    t33 = *((char **)t32);
    t34 = ((((char*)(t33))) + 40U);
    t35 = *((char **)t34);
    t36 = ((char*)((ng16)));
    xsi_vlog_generic_get_index_select_value(t26, 1, t31, t35, 2, t36, 32, 1);
    t38 = (t0 + 10596);
    t39 = *((char **)t38);
    t40 = ((((char*)(t39))) + 32U);
    t50 = *((char **)t40);
    t51 = (t0 + 10616);
    t57 = *((char **)t51);
    t61 = ((((char*)(t57))) + 40U);
    t66 = *((char **)t61);
    t68 = ((char*)((ng16)));
    xsi_vlog_generic_get_index_select_value(t37, 1, t50, t66, 2, t68, 32, 1);
    xsi_vlogfile_write(1, 0, ng65, 5, t0, (char)118, t22, 1, (char)118, t24, 1, (char)118, t26, 1, (char)118, t37, 1);
    xsi_set_current_line(299, ng0);
    t2 = (t0 + 10636);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 10656);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = ((char*)((ng18)));
    xsi_vlog_generic_get_index_select_value(t22, 1, t5, t9, 2, t10, 32, 1);
    t11 = (t0 + 10676);
    t12 = *((char **)t11);
    t14 = ((((char*)(t12))) + 32U);
    t15 = *((char **)t14);
    t16 = (t0 + 10696);
    t17 = *((char **)t16);
    t18 = ((((char*)(t17))) + 40U);
    t25 = *((char **)t18);
    t27 = ((char*)((ng18)));
    xsi_vlog_generic_get_index_select_value(t24, 1, t15, t25, 2, t27, 32, 1);
    t28 = (t0 + 10716);
    t29 = *((char **)t28);
    t30 = ((((char*)(t29))) + 32U);
    t31 = *((char **)t30);
    t32 = (t0 + 10736);
    t33 = *((char **)t32);
    t34 = ((((char*)(t33))) + 40U);
    t35 = *((char **)t34);
    t36 = ((char*)((ng18)));
    xsi_vlog_generic_get_index_select_value(t26, 1, t31, t35, 2, t36, 32, 1);
    t38 = (t0 + 10756);
    t39 = *((char **)t38);
    t40 = ((((char*)(t39))) + 32U);
    t50 = *((char **)t40);
    t51 = (t0 + 10776);
    t57 = *((char **)t51);
    t61 = ((((char*)(t57))) + 40U);
    t66 = *((char **)t61);
    t68 = ((char*)((ng18)));
    xsi_vlog_generic_get_index_select_value(t37, 1, t50, t66, 2, t68, 32, 1);
    xsi_vlogfile_write(1, 0, ng66, 5, t0, (char)118, t22, 1, (char)118, t24, 1, (char)118, t26, 1, (char)118, t37, 1);
    xsi_set_current_line(306, ng0);
    xsi_vlogfile_write(1, 0, ng42, 1, t0);
    xsi_set_current_line(307, ng0);
    xsi_vlogfile_write(1, 0, ng67, 1, t0);
    xsi_set_current_line(311, ng0);
    xsi_vlogfile_write(1, 0, ng68, 1, t0);
    xsi_set_current_line(312, ng0);
    t2 = ((char*)((ng5)));
    t3 = ((char*)((ng69)));
    t4 = ((char*)((ng70)));
    t5 = ((char*)((ng71)));
    t6 = (t0 + 5424);
    t7 = (t0 + 696);
    t8 = xsi_create_subprogram_invocation(t6, 0, t0, t7, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t7, t8);
    t9 = (t0 + 2616);
    xsi_vlogvar_assign_value(t9, t2, 0, 0, 2);
    t10 = (t0 + 2708);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 4);
    t11 = (t0 + 2800);
    xsi_vlogvar_assign_value(t11, t4, 0, 0, 32);
    t12 = (t0 + 2892);
    xsi_vlogvar_assign_value(t12, t5, 0, 0, 80);

LAB97:    t14 = (t0 + 5472);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    t18 = (t17 + 132U);
    t25 = *((char **)t18);
    t27 = (t25 + 0U);
    t28 = *((char **)t27);
    t13 = ((int  (*)(char *, char *))t28)(t0, t15);
    if (t13 != 0)
        goto LAB99;

LAB98:    t15 = (t0 + 696);
    xsi_vlog_subprogram_popinvocation(t15);

LAB96:    t29 = (t0 + 5472);
    t30 = *((char **)t29);
    t29 = (t0 + 696);
    t31 = (t0 + 5472);
    t32 = *((char **)t31);
    t31 = (t0 + 5424);
    t33 = 0;
    xsi_delete_subprogram_invocation(t29, t32, t0, t31, t33);
    xsi_set_current_line(316, ng0);
    xsi_vlogfile_write(1, 0, ng72, 1, t0);
    xsi_set_current_line(317, ng0);
    t2 = ((char*)((ng29)));
    t3 = ((char*)((ng5)));
    t4 = ((char*)((ng73)));
    t5 = ((char*)((ng74)));
    t6 = (t0 + 5424);
    t7 = (t0 + 696);
    t8 = xsi_create_subprogram_invocation(t6, 0, t0, t7, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t7, t8);
    t9 = (t0 + 2616);
    xsi_vlogvar_assign_value(t9, t2, 0, 0, 2);
    t10 = (t0 + 2708);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 4);
    t11 = (t0 + 2800);
    xsi_vlogvar_assign_value(t11, t4, 0, 0, 32);
    t12 = (t0 + 2892);
    xsi_vlogvar_assign_value(t12, t5, 0, 0, 80);

LAB101:    t14 = (t0 + 5472);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    t18 = (t17 + 132U);
    t25 = *((char **)t18);
    t27 = (t25 + 0U);
    t28 = *((char **)t27);
    t13 = ((int  (*)(char *, char *))t28)(t0, t15);
    if (t13 != 0)
        goto LAB103;

LAB102:    t15 = (t0 + 696);
    xsi_vlog_subprogram_popinvocation(t15);

LAB100:    t29 = (t0 + 5472);
    t30 = *((char **)t29);
    t29 = (t0 + 696);
    t31 = (t0 + 5472);
    t32 = *((char **)t31);
    t31 = (t0 + 5424);
    t33 = 0;
    xsi_delete_subprogram_invocation(t29, t32, t0, t31, t33);
    xsi_set_current_line(321, ng0);
    xsi_vlogfile_write(1, 0, ng75, 1, t0);
    xsi_set_current_line(322, ng0);
    t2 = ((char*)((ng69)));
    t3 = ((char*)((ng5)));
    t4 = ((char*)((ng69)));
    t5 = ((char*)((ng76)));
    t6 = (t0 + 5424);
    t7 = (t0 + 696);
    t8 = xsi_create_subprogram_invocation(t6, 0, t0, t7, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t7, t8);
    t9 = (t0 + 2616);
    xsi_vlogvar_assign_value(t9, t2, 0, 0, 2);
    t10 = (t0 + 2708);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 4);
    t11 = (t0 + 2800);
    xsi_vlogvar_assign_value(t11, t4, 0, 0, 32);
    t12 = (t0 + 2892);
    xsi_vlogvar_assign_value(t12, t5, 0, 0, 80);

LAB105:    t14 = (t0 + 5472);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    t18 = (t17 + 132U);
    t25 = *((char **)t18);
    t27 = (t25 + 0U);
    t28 = *((char **)t27);
    t13 = ((int  (*)(char *, char *))t28)(t0, t15);
    if (t13 != 0)
        goto LAB107;

LAB106:    t15 = (t0 + 696);
    xsi_vlog_subprogram_popinvocation(t15);

LAB104:    t29 = (t0 + 5472);
    t30 = *((char **)t29);
    t29 = (t0 + 696);
    t31 = (t0 + 5472);
    t32 = *((char **)t31);
    t31 = (t0 + 5424);
    t33 = 0;
    xsi_delete_subprogram_invocation(t29, t32, t0, t31, t33);
    xsi_set_current_line(326, ng0);
    xsi_vlogfile_write(1, 0, ng77, 1, t0);
    xsi_set_current_line(327, ng0);
    t2 = ((char*)((ng78)));
    t3 = ((char*)((ng5)));
    t4 = ((char*)((ng79)));
    t5 = ((char*)((ng80)));
    t6 = (t0 + 5424);
    t7 = (t0 + 696);
    t8 = xsi_create_subprogram_invocation(t6, 0, t0, t7, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t7, t8);
    t9 = (t0 + 2616);
    xsi_vlogvar_assign_value(t9, t2, 0, 0, 2);
    t10 = (t0 + 2708);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 4);
    t11 = (t0 + 2800);
    xsi_vlogvar_assign_value(t11, t4, 0, 0, 32);
    t12 = (t0 + 2892);
    xsi_vlogvar_assign_value(t12, t5, 0, 0, 80);

LAB109:    t14 = (t0 + 5472);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    t18 = (t17 + 132U);
    t25 = *((char **)t18);
    t27 = (t25 + 0U);
    t28 = *((char **)t27);
    t13 = ((int  (*)(char *, char *))t28)(t0, t15);
    if (t13 != 0)
        goto LAB111;

LAB110:    t15 = (t0 + 696);
    xsi_vlog_subprogram_popinvocation(t15);

LAB108:    t29 = (t0 + 5472);
    t30 = *((char **)t29);
    t29 = (t0 + 696);
    t31 = (t0 + 5472);
    t32 = *((char **)t31);
    t31 = (t0 + 5424);
    t33 = 0;
    xsi_delete_subprogram_invocation(t29, t32, t0, t31, t33);
    xsi_set_current_line(332, ng0);
    xsi_vlogfile_write(1, 0, ng42, 1, t0);
    xsi_set_current_line(333, ng0);
    xsi_vlogfile_write(1, 0, ng81, 1, t0);
    xsi_set_current_line(336, ng0);
    t2 = (t0 + 1696);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t5 = (t0 + 1696);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    t8 = (t0 + 1696);
    t9 = (t8 + 36U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng6)));
    t12 = ((char*)((ng16)));
    xsi_vlog_generic_get_array_select_value(t22, 32, t4, t7, t10, 2, 2, t11, 32, 1, t12, 32, 1);
    t14 = (t0 + 1696);
    t15 = (t14 + 32U);
    t16 = *((char **)t15);
    t17 = (t0 + 1696);
    t18 = (t17 + 40U);
    t25 = *((char **)t18);
    t27 = (t0 + 1696);
    t28 = (t27 + 36U);
    t29 = *((char **)t28);
    t30 = ((char*)((ng1)));
    t31 = ((char*)((ng16)));
    xsi_vlog_generic_get_array_select_value(t24, 32, t16, t25, t29, 2, 2, t30, 32, 1, t31, 32, 1);
    memset(t26, 0, 8);
    t32 = (t22 + 4U);
    t33 = (t24 + 4U);
    if (*((unsigned int *)t22) != *((unsigned int *)t24))
        goto LAB113;

LAB112:    if (*((unsigned int *)t32) != *((unsigned int *)t33))
        goto LAB113;

LAB114:    memset(t37, 0, 8);
    t34 = (t37 + 4U);
    t35 = (t26 + 4U);
    t19 = *((unsigned int *)t35);
    t20 = (~(t19));
    t21 = *((unsigned int *)t26);
    t41 = (t21 & t20);
    t42 = (t41 & 1U);
    if (t42 != 0)
        goto LAB115;

LAB116:    if (*((unsigned int *)t35) != 0)
        goto LAB117;

LAB118:    t36 = (t37 + 4U);
    t43 = *((unsigned int *)t37);
    t44 = (!(t43));
    t45 = *((unsigned int *)t36);
    t46 = (t44 || t45);
    if (t46 > 0)
        goto LAB119;

LAB120:    memcpy(t78, t37, 8);

LAB121:    t100 = (t78 + 4U);
    t101 = *((unsigned int *)t100);
    t102 = (~(t101));
    t103 = *((unsigned int *)t78);
    t104 = (t103 & t102);
    t105 = (t104 != 0);
    if (t105 > 0)
        goto LAB133;

LAB134:    xsi_set_current_line(340, ng0);
    xsi_vlogfile_write(1, 0, ng83, 1, t0);

LAB135:    xsi_set_current_line(343, ng0);
    t2 = (t0 + 1788);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t5 = (t0 + 1788);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    t8 = (t0 + 1788);
    t9 = (t8 + 36U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng1)));
    t12 = ((char*)((ng16)));
    xsi_vlog_generic_get_array_select_value(t26, 1, t4, t7, t10, 2, 2, t11, 32, 1, t12, 32, 1);
    memset(t24, 0, 8);
    t14 = (t24 + 4U);
    t15 = (t26 + 4U);
    t19 = *((unsigned int *)t15);
    t20 = (~(t19));
    t21 = *((unsigned int *)t26);
    t41 = (t21 & t20);
    t42 = (t41 & 1U);
    if (t42 != 0)
        goto LAB136;

LAB137:    if (*((unsigned int *)t15) != 0)
        goto LAB138;

LAB139:    t16 = (t24 + 4U);
    t43 = *((unsigned int *)t24);
    t44 = *((unsigned int *)t16);
    t45 = (t43 || t44);
    if (t45 > 0)
        goto LAB140;

LAB141:    t46 = *((unsigned int *)t24);
    t47 = (~(t46));
    t48 = *((unsigned int *)t16);
    t49 = (t47 || t48);
    if (t49 > 0)
        goto LAB142;

LAB143:    if (*((unsigned int *)t16) > 0)
        goto LAB144;

LAB145:    if (*((unsigned int *)t24) > 0)
        goto LAB146;

LAB147:    memcpy(t22, t18, 8);

LAB148:    xsi_vlogfile_write(1, 0, ng84, 2, t0, (char)118, t22, 24);
    xsi_set_current_line(344, ng0);
    t2 = (t0 + 1788);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t5 = (t0 + 1788);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    t8 = (t0 + 1788);
    t9 = (t8 + 36U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng6)));
    t12 = ((char*)((ng1)));
    xsi_vlog_generic_get_array_select_value(t26, 1, t4, t7, t10, 2, 2, t11, 32, 1, t12, 32, 1);
    memset(t24, 0, 8);
    t14 = (t24 + 4U);
    t15 = (t26 + 4U);
    t19 = *((unsigned int *)t15);
    t20 = (~(t19));
    t21 = *((unsigned int *)t26);
    t41 = (t21 & t20);
    t42 = (t41 & 1U);
    if (t42 != 0)
        goto LAB149;

LAB150:    if (*((unsigned int *)t15) != 0)
        goto LAB151;

LAB152:    t16 = (t24 + 4U);
    t43 = *((unsigned int *)t24);
    t44 = *((unsigned int *)t16);
    t45 = (t43 || t44);
    if (t45 > 0)
        goto LAB153;

LAB154:    t46 = *((unsigned int *)t24);
    t47 = (~(t46));
    t48 = *((unsigned int *)t16);
    t49 = (t47 || t48);
    if (t49 > 0)
        goto LAB155;

LAB156:    if (*((unsigned int *)t16) > 0)
        goto LAB157;

LAB158:    if (*((unsigned int *)t24) > 0)
        goto LAB159;

LAB160:    memcpy(t22, t18, 8);

LAB161:    xsi_vlogfile_write(1, 0, ng87, 2, t0, (char)118, t22, 24);
    xsi_set_current_line(345, ng0);
    t2 = (t0 + 1788);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t5 = (t0 + 1788);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    t8 = (t0 + 1788);
    t9 = (t8 + 36U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng16)));
    t12 = ((char*)((ng1)));
    xsi_vlog_generic_get_array_select_value(t26, 1, t4, t7, t10, 2, 2, t11, 32, 1, t12, 32, 1);
    memset(t24, 0, 8);
    t14 = (t24 + 4U);
    t15 = (t26 + 4U);
    t19 = *((unsigned int *)t15);
    t20 = (~(t19));
    t21 = *((unsigned int *)t26);
    t41 = (t21 & t20);
    t42 = (t41 & 1U);
    if (t42 != 0)
        goto LAB162;

LAB163:    if (*((unsigned int *)t15) != 0)
        goto LAB164;

LAB165:    t16 = (t24 + 4U);
    t43 = *((unsigned int *)t24);
    t44 = *((unsigned int *)t16);
    t45 = (t43 || t44);
    if (t45 > 0)
        goto LAB166;

LAB167:    t46 = *((unsigned int *)t24);
    t47 = (~(t46));
    t48 = *((unsigned int *)t16);
    t49 = (t47 || t48);
    if (t49 > 0)
        goto LAB168;

LAB169:    if (*((unsigned int *)t16) > 0)
        goto LAB170;

LAB171:    if (*((unsigned int *)t24) > 0)
        goto LAB172;

LAB173:    memcpy(t22, t18, 8);

LAB174:    xsi_vlogfile_write(1, 0, ng88, 2, t0, (char)118, t22, 24);
    xsi_set_current_line(346, ng0);
    t2 = (t0 + 1788);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t5 = (t0 + 1788);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    t8 = (t0 + 1788);
    t9 = (t8 + 36U);
    t10 = *((char **)t9);
    t11 = ((char*)((ng18)));
    t12 = ((char*)((ng1)));
    xsi_vlog_generic_get_array_select_value(t26, 1, t4, t7, t10, 2, 2, t11, 32, 1, t12, 32, 1);
    memset(t24, 0, 8);
    t14 = (t24 + 4U);
    t15 = (t26 + 4U);
    t19 = *((unsigned int *)t15);
    t20 = (~(t19));
    t21 = *((unsigned int *)t26);
    t41 = (t21 & t20);
    t42 = (t41 & 1U);
    if (t42 != 0)
        goto LAB175;

LAB176:    if (*((unsigned int *)t15) != 0)
        goto LAB177;

LAB178:    t16 = (t24 + 4U);
    t43 = *((unsigned int *)t24);
    t44 = *((unsigned int *)t16);
    t45 = (t43 || t44);
    if (t45 > 0)
        goto LAB179;

LAB180:    t46 = *((unsigned int *)t24);
    t47 = (~(t46));
    t48 = *((unsigned int *)t16);
    t49 = (t47 || t48);
    if (t49 > 0)
        goto LAB181;

LAB182:    if (*((unsigned int *)t16) > 0)
        goto LAB183;

LAB184:    if (*((unsigned int *)t24) > 0)
        goto LAB185;

LAB186:    memcpy(t22, t18, 8);

LAB187:    xsi_vlogfile_write(1, 0, ng89, 2, t0, (char)118, t22, 24);
    xsi_set_current_line(351, ng0);
    xsi_vlogfile_write(1, 0, ng42, 1, t0);
    xsi_set_current_line(352, ng0);
    xsi_vlogfile_write(1, 0, ng90, 1, t0);
    xsi_set_current_line(353, ng0);
    xsi_set_current_line(353, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1880);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB188:    t2 = (t0 + 1880);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t22, 0, 8);
    xsi_vlog_signed_less(t22, 32, t4, 32, t5, 32);
    t6 = (t22 + 4U);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t22);
    t41 = (t21 & t20);
    t42 = (t41 != 0);
    if (t42 > 0)
        goto LAB189;

LAB190:    xsi_set_current_line(367, ng0);
    xsi_vlogfile_write(1, 0, ng42, 1, t0);
    xsi_set_current_line(368, ng0);
    xsi_vlogfile_write(1, 0, ng94, 1, t0);
    xsi_set_current_line(369, ng0);
    t2 = (t0 + 10796);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 10816);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = (t0 + 10836);
    t11 = *((char **)t10);
    t12 = ((((char*)(t11))) + 36U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng69)));
    xsi_vlog_generic_get_array_select_value(t22, 32, t5, t9, t14, 2, 1, t15, 6, 2);
    t16 = (t0 + 10856);
    t17 = *((char **)t16);
    t18 = ((((char*)(t17))) + 32U);
    t25 = *((char **)t18);
    t27 = (t0 + 10876);
    t28 = *((char **)t27);
    t29 = ((((char*)(t28))) + 40U);
    t30 = *((char **)t29);
    t31 = (t0 + 10896);
    t32 = *((char **)t31);
    t33 = ((((char*)(t32))) + 36U);
    t34 = *((char **)t33);
    t35 = ((char*)((ng69)));
    xsi_vlog_generic_get_array_select_value(t24, 32, t25, t30, t34, 2, 1, t35, 6, 2);
    xsi_vlogfile_write(1, 0, ng95, 3, t0, (char)118, t22, 32, (char)118, t24, 32);
    xsi_set_current_line(372, ng0);
    t2 = (t0 + 10916);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 10936);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = (t0 + 10956);
    t11 = *((char **)t10);
    t12 = ((((char*)(t11))) + 36U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng97)));
    xsi_vlog_generic_get_array_select_value(t22, 32, t5, t9, t14, 2, 1, t15, 6, 2);
    t16 = (t0 + 10976);
    t17 = *((char **)t16);
    t18 = ((((char*)(t17))) + 32U);
    t25 = *((char **)t18);
    t27 = (t0 + 10996);
    t28 = *((char **)t27);
    t29 = ((((char*)(t28))) + 40U);
    t30 = *((char **)t29);
    t31 = (t0 + 11016);
    t32 = *((char **)t31);
    t33 = ((((char*)(t32))) + 36U);
    t34 = *((char **)t33);
    t35 = ((char*)((ng97)));
    xsi_vlog_generic_get_array_select_value(t24, 32, t25, t30, t34, 2, 1, t35, 6, 2);
    xsi_vlogfile_write(1, 0, ng96, 3, t0, (char)118, t22, 32, (char)118, t24, 32);
    xsi_set_current_line(375, ng0);
    t2 = (t0 + 11036);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 11056);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = (t0 + 11076);
    t11 = *((char **)t10);
    t12 = ((((char*)(t11))) + 36U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng99)));
    xsi_vlog_generic_get_array_select_value(t22, 32, t5, t9, t14, 2, 1, t15, 6, 2);
    t16 = (t0 + 11096);
    t17 = *((char **)t16);
    t18 = ((((char*)(t17))) + 32U);
    t25 = *((char **)t18);
    t27 = (t0 + 11116);
    t28 = *((char **)t27);
    t29 = ((((char*)(t28))) + 40U);
    t30 = *((char **)t29);
    t31 = (t0 + 11136);
    t32 = *((char **)t31);
    t33 = ((((char*)(t32))) + 36U);
    t34 = *((char **)t33);
    t35 = ((char*)((ng99)));
    xsi_vlog_generic_get_array_select_value(t24, 32, t25, t30, t34, 2, 1, t35, 6, 2);
    xsi_vlogfile_write(1, 0, ng98, 3, t0, (char)118, t22, 32, (char)118, t24, 32);
    xsi_set_current_line(378, ng0);
    t2 = (t0 + 11156);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 11176);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = (t0 + 11196);
    t11 = *((char **)t10);
    t12 = ((((char*)(t11))) + 36U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng101)));
    xsi_vlog_generic_get_array_select_value(t22, 32, t5, t9, t14, 2, 1, t15, 6, 2);
    t16 = (t0 + 11216);
    t17 = *((char **)t16);
    t18 = ((((char*)(t17))) + 32U);
    t25 = *((char **)t18);
    t27 = (t0 + 11236);
    t28 = *((char **)t27);
    t29 = ((((char*)(t28))) + 40U);
    t30 = *((char **)t29);
    t31 = (t0 + 11256);
    t32 = *((char **)t31);
    t33 = ((((char*)(t32))) + 36U);
    t34 = *((char **)t33);
    t35 = ((char*)((ng101)));
    xsi_vlog_generic_get_array_select_value(t24, 32, t25, t30, t34, 2, 1, t35, 6, 2);
    xsi_vlogfile_write(1, 0, ng100, 3, t0, (char)118, t22, 32, (char)118, t24, 32);
    xsi_set_current_line(385, ng0);
    xsi_vlogfile_write(1, 0, ng42, 1, t0);
    xsi_set_current_line(386, ng0);
    xsi_vlogfile_write(1, 0, ng43, 1, t0);
    xsi_set_current_line(387, ng0);
    t2 = (t0 + 2432);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t5 = (t0 + 2524);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    xsi_vlogfile_write(1, 0, ng102, 3, t0, (char)119, t4, 32, (char)119, t7, 32);
    xsi_set_current_line(389, ng0);
    t2 = (t0 + 2524);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t22, 0, 8);
    xsi_vlog_signed_equal(t22, 32, t4, 32, t5, 32);
    t6 = (t22 + 4U);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t22);
    t41 = (t21 & t20);
    t42 = (t41 != 0);
    if (t42 > 0)
        goto LAB199;

LAB200:    xsi_set_current_line(392, ng0);
    xsi_vlogfile_write(1, 0, ng104, 1, t0);

LAB201:    xsi_set_current_line(393, ng0);
    xsi_vlogfile_write(1, 0, ng43, 1, t0);
    xsi_set_current_line(395, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

LAB18:    *((unsigned int *)t37) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB19;

LAB20:    *((unsigned int *)t24) = 1;
    goto LAB23;

LAB22:    *((unsigned int *)t24) = 1;
    *((unsigned int *)t50) = 1;
    goto LAB23;

LAB24:    t61 = ((char*)((ng48)));
    goto LAB25;

LAB26:    t66 = ((char*)((ng49)));
    goto LAB27;

LAB28:    xsi_vlog_unsigned_bit_combine(t23, 152, t61, 152, t66, 152);
    goto LAB32;

LAB30:    memcpy(t23, t61, 40);
    goto LAB32;

LAB35:    *((unsigned int *)t37) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB36;

LAB37:    *((unsigned int *)t24) = 1;
    goto LAB40;

LAB39:    *((unsigned int *)t24) = 1;
    *((unsigned int *)t50) = 1;
    goto LAB40;

LAB41:    t61 = ((char*)((ng48)));
    goto LAB42;

LAB43:    t66 = ((char*)((ng52)));
    goto LAB44;

LAB45:    xsi_vlog_unsigned_bit_combine(t23, 160, t61, 160, t66, 160);
    goto LAB49;

LAB47:    memcpy(t23, t61, 40);
    goto LAB49;

LAB52:    *((unsigned int *)t37) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB53;

LAB54:    *((unsigned int *)t24) = 1;
    goto LAB57;

LAB56:    *((unsigned int *)t24) = 1;
    *((unsigned int *)t50) = 1;
    goto LAB57;

LAB58:    t61 = ((char*)((ng55)));
    goto LAB59;

LAB60:    t66 = ((char*)((ng56)));
    goto LAB61;

LAB62:    xsi_vlog_unsigned_bit_combine(t67, 168, t61, 168, t66, 168);
    goto LAB66;

LAB64:    memcpy(t67, t61, 48);
    goto LAB66;

LAB69:    *((unsigned int *)t37) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB70;

LAB71:    *((unsigned int *)t24) = 1;
    goto LAB74;

LAB73:    *((unsigned int *)t24) = 1;
    *((unsigned int *)t50) = 1;
    goto LAB74;

LAB75:    t61 = ((char*)((ng55)));
    goto LAB76;

LAB77:    t66 = ((char*)((ng59)));
    goto LAB78;

LAB79:    xsi_vlog_unsigned_bit_combine(t67, 168, t61, 168, t66, 168);
    goto LAB83;

LAB81:    memcpy(t67, t61, 48);
    goto LAB83;

LAB85:    xsi_set_current_line(271, ng0);
    t6 = (t0 + 5800);
    *((int *)t6) = 1;
    *((char **)t1) = &&LAB87;
    goto LAB1;

LAB87:    t2 = (t0 + 10132);
    t13 = *((int *)t2);
    *((int *)t2) = (t13 - 1);
    goto LAB84;

LAB91:    t5 = (t0 + 5508U);
    *((char **)t5) = &&LAB89;
    goto LAB1;

LAB93:    xsi_set_current_line(283, ng0);
    t6 = (t0 + 5808);
    *((int *)t6) = 1;
    *((char **)t1) = &&LAB95;
    goto LAB1;

LAB95:    t2 = (t0 + 10136);
    t13 = *((int *)t2);
    *((int *)t2) = (t13 - 1);
    goto LAB92;

LAB99:    t14 = (t0 + 5508U);
    *((char **)t14) = &&LAB97;
    goto LAB1;

LAB103:    t14 = (t0 + 5508U);
    *((char **)t14) = &&LAB101;
    goto LAB1;

LAB107:    t14 = (t0 + 5508U);
    *((char **)t14) = &&LAB105;
    goto LAB1;

LAB111:    t14 = (t0 + 5508U);
    *((char **)t14) = &&LAB109;
    goto LAB1;

LAB113:    *((unsigned int *)t26) = 1;
    goto LAB114;

LAB115:    *((unsigned int *)t37) = 1;
    goto LAB118;

LAB117:    *((unsigned int *)t37) = 1;
    *((unsigned int *)t34) = 1;
    goto LAB118;

LAB119:    t38 = (t0 + 1788);
    t39 = (t38 + 32U);
    t40 = *((char **)t39);
    t50 = (t0 + 1788);
    t51 = (t50 + 40U);
    t57 = *((char **)t51);
    t61 = (t0 + 1788);
    t66 = (t61 + 36U);
    t68 = *((char **)t66);
    t71 = ((char*)((ng6)));
    t72 = ((char*)((ng16)));
    xsi_vlog_generic_get_array_select_value(t70, 1, t40, t57, t68, 2, 2, t71, 32, 1, t72, 32, 1);
    memset(t69, 0, 8);
    t73 = (t69 + 4U);
    t74 = (t70 + 4U);
    t47 = *((unsigned int *)t74);
    t48 = (~(t47));
    t49 = *((unsigned int *)t70);
    t52 = (t49 & t48);
    t53 = (t52 & 1U);
    if (t53 != 0)
        goto LAB125;

LAB123:    if (*((unsigned int *)t74) == 0)
        goto LAB122;

LAB124:    *((unsigned int *)t69) = 1;
    *((unsigned int *)t73) = 1;

LAB125:    memset(t75, 0, 8);
    t76 = (t75 + 4U);
    t77 = (t69 + 4U);
    t54 = *((unsigned int *)t77);
    t55 = (~(t54));
    t56 = *((unsigned int *)t69);
    t58 = (t56 & t55);
    t59 = (t58 & 1U);
    if (t59 != 0)
        goto LAB126;

LAB127:    if (*((unsigned int *)t77) != 0)
        goto LAB128;

LAB129:    t60 = *((unsigned int *)t37);
    t62 = *((unsigned int *)t75);
    t63 = (t60 | t62);
    *((unsigned int *)t78) = t63;
    t79 = (t37 + 4U);
    t80 = (t75 + 4U);
    t81 = (t78 + 4U);
    t64 = *((unsigned int *)t79);
    t65 = *((unsigned int *)t80);
    t82 = (t64 | t65);
    *((unsigned int *)t81) = t82;
    t83 = *((unsigned int *)t81);
    t84 = (t83 != 0);
    if (t84 == 1)
        goto LAB130;

LAB131:
LAB132:    goto LAB121;

LAB122:    *((unsigned int *)t69) = 1;
    goto LAB125;

LAB126:    *((unsigned int *)t75) = 1;
    goto LAB129;

LAB128:    *((unsigned int *)t75) = 1;
    *((unsigned int *)t76) = 1;
    goto LAB129;

LAB130:    t85 = *((unsigned int *)t78);
    t86 = *((unsigned int *)t81);
    *((unsigned int *)t78) = (t85 | t86);
    t87 = (t37 + 4U);
    t88 = (t75 + 4U);
    t89 = *((unsigned int *)t87);
    t90 = (~(t89));
    t91 = *((unsigned int *)t37);
    t13 = (t91 & t90);
    t92 = *((unsigned int *)t88);
    t93 = (~(t92));
    t94 = *((unsigned int *)t75);
    t95 = (t94 & t93);
    t96 = (~(t13));
    t97 = (~(t95));
    t98 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t98 & t96);
    t99 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t99 & t97);
    goto LAB132;

LAB133:    xsi_set_current_line(338, ng0);
    xsi_vlogfile_write(1, 0, ng82, 1, t0);
    goto LAB135;

LAB136:    *((unsigned int *)t24) = 1;
    goto LAB139;

LAB138:    *((unsigned int *)t24) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB139;

LAB140:    t17 = ((char*)((ng85)));
    goto LAB141;

LAB142:    t18 = ((char*)((ng86)));
    goto LAB143;

LAB144:    xsi_vlog_unsigned_bit_combine(t22, 24, t17, 24, t18, 24);
    goto LAB148;

LAB146:    memcpy(t22, t17, 8);
    goto LAB148;

LAB149:    *((unsigned int *)t24) = 1;
    goto LAB152;

LAB151:    *((unsigned int *)t24) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB152;

LAB153:    t17 = ((char*)((ng85)));
    goto LAB154;

LAB155:    t18 = ((char*)((ng86)));
    goto LAB156;

LAB157:    xsi_vlog_unsigned_bit_combine(t22, 24, t17, 24, t18, 24);
    goto LAB161;

LAB159:    memcpy(t22, t17, 8);
    goto LAB161;

LAB162:    *((unsigned int *)t24) = 1;
    goto LAB165;

LAB164:    *((unsigned int *)t24) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB165;

LAB166:    t17 = ((char*)((ng85)));
    goto LAB167;

LAB168:    t18 = ((char*)((ng86)));
    goto LAB169;

LAB170:    xsi_vlog_unsigned_bit_combine(t22, 24, t17, 24, t18, 24);
    goto LAB174;

LAB172:    memcpy(t22, t17, 8);
    goto LAB174;

LAB175:    *((unsigned int *)t24) = 1;
    goto LAB178;

LAB177:    *((unsigned int *)t24) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB178;

LAB179:    t17 = ((char*)((ng85)));
    goto LAB180;

LAB181:    t18 = ((char*)((ng86)));
    goto LAB182;

LAB183:    xsi_vlog_unsigned_bit_combine(t22, 24, t17, 24, t18, 24);
    goto LAB187;

LAB185:    memcpy(t22, t17, 8);
    goto LAB187;

LAB189:    xsi_set_current_line(353, ng0);

LAB191:    xsi_set_current_line(354, ng0);
    t7 = (t0 + 1880);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    xsi_vlogfile_write(1, 0, ng91, 2, t0, (char)119, t9, 32);
    xsi_set_current_line(355, ng0);
    xsi_set_current_line(355, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1972);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB192:    t2 = (t0 + 1972);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t22, 0, 8);
    xsi_vlog_signed_less(t22, 32, t4, 32, t5, 32);
    t6 = (t22 + 4U);
    t19 = *((unsigned int *)t6);
    t20 = (~(t19));
    t21 = *((unsigned int *)t22);
    t41 = (t21 & t20);
    t42 = (t41 != 0);
    if (t42 > 0)
        goto LAB193;

LAB194:    xsi_set_current_line(353, ng0);
    t2 = (t0 + 1880);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng6)));
    memset(t22, 0, 8);
    xsi_vlog_signed_add(t22, 32, t4, 32, t5, 32);
    t6 = (t0 + 1880);
    xsi_vlogvar_assign_value(t6, t22, 0, 0, 32);
    goto LAB188;

LAB193:    xsi_set_current_line(355, ng0);

LAB195:    xsi_set_current_line(356, ng0);
    t7 = (t0 + 1788);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    t10 = (t0 + 1788);
    t11 = (t10 + 40U);
    t12 = *((char **)t11);
    t14 = (t0 + 1788);
    t15 = (t14 + 36U);
    t16 = *((char **)t15);
    t17 = (t0 + 1880);
    t18 = (t17 + 32U);
    t25 = *((char **)t18);
    t27 = (t0 + 1972);
    t28 = (t27 + 32U);
    t29 = *((char **)t28);
    xsi_vlog_generic_get_array_select_value(t24, 1, t9, t12, t16, 2, 2, t25, 32, 1, t29, 32, 1);
    t30 = (t24 + 4U);
    t43 = *((unsigned int *)t30);
    t44 = (~(t43));
    t45 = *((unsigned int *)t24);
    t46 = (t45 & t44);
    t47 = (t46 != 0);
    if (t47 > 0)
        goto LAB196;

LAB197:    xsi_set_current_line(360, ng0);
    t2 = (t0 + 1972);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, ng93, 2, t0, (char)119, t4, 32);

LAB198:    xsi_set_current_line(355, ng0);
    t2 = (t0 + 1972);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng6)));
    memset(t22, 0, 8);
    xsi_vlog_signed_add(t22, 32, t4, 32, t5, 32);
    t6 = (t0 + 1972);
    xsi_vlogvar_assign_value(t6, t22, 0, 0, 32);
    goto LAB192;

LAB196:    xsi_set_current_line(357, ng0);
    t31 = (t0 + 1972);
    t32 = (t31 + 32U);
    t33 = *((char **)t32);
    t34 = (t0 + 1696);
    t35 = (t34 + 32U);
    t36 = *((char **)t35);
    t38 = (t0 + 1696);
    t39 = (t38 + 40U);
    t40 = *((char **)t39);
    t50 = (t0 + 1696);
    t51 = (t50 + 36U);
    t57 = *((char **)t51);
    t61 = (t0 + 1880);
    t66 = (t61 + 32U);
    t68 = *((char **)t66);
    t71 = (t0 + 1972);
    t72 = (t71 + 32U);
    t73 = *((char **)t72);
    xsi_vlog_generic_get_array_select_value(t26, 32, t36, t40, t57, 2, 2, t68, 32, 1, t73, 32, 1);
    t74 = (t0 + 1696);
    t76 = (t74 + 32U);
    t77 = *((char **)t76);
    t79 = (t0 + 1696);
    t80 = (t79 + 40U);
    t81 = *((char **)t80);
    t87 = (t0 + 1696);
    t88 = (t87 + 36U);
    t100 = *((char **)t88);
    t106 = (t0 + 1880);
    t107 = (t106 + 32U);
    t108 = *((char **)t107);
    t109 = (t0 + 1972);
    t110 = (t109 + 32U);
    t111 = *((char **)t110);
    xsi_vlog_generic_get_array_select_value(t37, 32, t77, t81, t100, 2, 2, t108, 32, 1, t111, 32, 1);
    xsi_vlogfile_write(1, 0, ng92, 4, t0, (char)119, t33, 32, (char)118, t26, 32, (char)118, t37, 32);
    goto LAB198;

LAB199:    xsi_set_current_line(390, ng0);
    xsi_vlogfile_write(1, 0, ng103, 1, t0);
    goto LAB201;

}


extern void work_m_00000000000955471609_1293442911_init()
{
	static char *pe[] = {(void *)I12_0,(void *)A13_1,(void *)I16_2,(void *)A17_3,(void *)A50_4,(void *)A65_5,(void *)A72_6,(void *)I88_7,(void *)A160_8,(void *)A174_9,(void *)A185_10,(void *)A192_11,(void *)A199_12,(void *)A207_13,(void *)A216_14,(void *)A223_15,(void *)I233_16};
	static char *se[] = {(void *)sp_clear_shadow,(void *)sp_check_reg,(void *)sp_bram_diagnostic};
	xsi_register_didat("work_m_00000000000955471609_1293442911", "isim/_tmp/work/m_00000000000955471609_1293442911.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
