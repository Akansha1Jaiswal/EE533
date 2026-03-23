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
static const char *ng0 = "C:/Documents and Settings/student/My Documents/GPU_MM/gpu_control_unit.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {6U, 0U};
static int ng3[] = {1, 0};
static unsigned int ng4[] = {7U, 0U};
static unsigned int ng5[] = {8U, 0U};
static unsigned int ng6[] = {9U, 0U};
static unsigned int ng7[] = {17U, 0U};
static unsigned int ng8[] = {18U, 0U};
static unsigned int ng9[] = {10U, 0U};
static unsigned int ng10[] = {19U, 0U};
static unsigned int ng11[] = {4U, 0U};
static unsigned int ng12[] = {1U, 0U};
static unsigned int ng13[] = {24U, 0U};
static unsigned int ng14[] = {30U, 0U};
static unsigned int ng15[] = {31U, 0U};



static void A37_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    t1 = (t0 + 2348U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(37, ng0);
    t2 = (t0 + 2528);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(37, ng0);

LAB5:    xsi_set_current_line(38, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t0 + 1228);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(39, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(40, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1412);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(41, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1504);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(42, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1596);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(43, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(44, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1780);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(45, ng0);
    t2 = (t0 + 652U);
    t3 = *((char **)t2);
    t2 = (t0 + 1872);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    xsi_set_current_line(50, ng0);
    t2 = (t0 + 740U);
    t3 = *((char **)t2);
    t2 = (t3 + 4U);
    t5 = *((unsigned int *)t2);
    t6 = (~(t5));
    t7 = *((unsigned int *)t3);
    t8 = (t7 & t6);
    t9 = (t8 != 0);
    if (t9 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 828U);
    t3 = *((char **)t2);
    t2 = (t3 + 4U);
    t5 = *((unsigned int *)t2);
    t6 = (~(t5));
    t7 = *((unsigned int *)t3);
    t8 = (t7 & t6);
    t9 = (t8 != 0);
    if (t9 > 0)
        goto LAB39;

LAB40:    xsi_set_current_line(83, ng0);
    t2 = (t0 + 916U);
    t3 = *((char **)t2);
    t2 = (t3 + 4U);
    t5 = *((unsigned int *)t2);
    t6 = (~(t5));
    t7 = *((unsigned int *)t3);
    t8 = (t7 & t6);
    t9 = (t8 != 0);
    if (t9 > 0)
        goto LAB60;

LAB61:    xsi_set_current_line(103, ng0);
    t2 = (t0 + 1004U);
    t4 = *((char **)t2);
    t2 = (t4 + 4U);
    t5 = *((unsigned int *)t2);
    t6 = (~(t5));
    t7 = *((unsigned int *)t4);
    t8 = (t7 & t6);
    t9 = (t8 != 0);
    if (t9 > 0)
        goto LAB75;

LAB76:
LAB77:
LAB62:
LAB41:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(50, ng0);

LAB9:    xsi_set_current_line(51, ng0);
    t4 = (t0 + 564U);
    t10 = *((char **)t4);

LAB10:    t4 = ((char*)((ng2)));
    t11 = xsi_vlog_unsigned_case_compare(t10, 5, t4, 5);
    if (t11 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t11 = xsi_vlog_unsigned_case_compare(t10, 5, t2, 5);
    if (t11 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng5)));
    t11 = xsi_vlog_unsigned_case_compare(t10, 5, t2, 5);
    if (t11 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng6)));
    t11 = xsi_vlog_unsigned_case_compare(t10, 5, t2, 5);
    if (t11 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng7)));
    t11 = xsi_vlog_unsigned_case_compare(t10, 5, t2, 5);
    if (t11 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng8)));
    t11 = xsi_vlog_unsigned_case_compare(t10, 5, t2, 5);
    if (t11 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng9)));
    t11 = xsi_vlog_unsigned_case_compare(t10, 5, t2, 5);
    if (t11 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng11)));
    t11 = xsi_vlog_unsigned_case_compare(t10, 5, t2, 5);
    if (t11 == 1)
        goto LAB25;

LAB26:
LAB28:
LAB27:    xsi_set_current_line(60, ng0);

LAB38:
LAB29:    goto LAB8;

LAB11:    xsi_set_current_line(52, ng0);

LAB30:    xsi_set_current_line(52, ng0);
    t12 = ((char*)((ng3)));
    t13 = (t0 + 1228);
    xsi_vlogvar_assign_value(t13, t12, 0, 0, 1);
    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    goto LAB29;

LAB13:    xsi_set_current_line(53, ng0);

LAB31:    xsi_set_current_line(53, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 1228);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    goto LAB29;

LAB15:    xsi_set_current_line(54, ng0);

LAB32:    xsi_set_current_line(54, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 1228);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    goto LAB29;

LAB17:    xsi_set_current_line(55, ng0);

LAB33:    xsi_set_current_line(55, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 1228);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 1320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    goto LAB29;

LAB19:    xsi_set_current_line(56, ng0);

LAB34:    xsi_set_current_line(56, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 1228);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 1320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    goto LAB29;

LAB21:    xsi_set_current_line(57, ng0);

LAB35:    xsi_set_current_line(57, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 1228);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 1320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    goto LAB29;

LAB23:    xsi_set_current_line(58, ng0);

LAB36:    xsi_set_current_line(58, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 1228);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 1320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    goto LAB29;

LAB25:    xsi_set_current_line(59, ng0);

LAB37:    xsi_set_current_line(59, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 1228);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 1320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    goto LAB29;

LAB39:    xsi_set_current_line(67, ng0);

LAB42:    xsi_set_current_line(68, ng0);
    t4 = (t0 + 564U);
    t12 = *((char **)t4);

LAB43:    t4 = ((char*)((ng1)));
    t11 = xsi_vlog_unsigned_case_compare(t12, 5, t4, 5);
    if (t11 == 1)
        goto LAB44;

LAB45:    t2 = ((char*)((ng7)));
    t11 = xsi_vlog_unsigned_case_compare(t12, 5, t2, 5);
    if (t11 == 1)
        goto LAB46;

LAB47:    t2 = ((char*)((ng8)));
    t11 = xsi_vlog_unsigned_case_compare(t12, 5, t2, 5);
    if (t11 == 1)
        goto LAB48;

LAB49:    t2 = ((char*)((ng11)));
    t11 = xsi_vlog_unsigned_case_compare(t12, 5, t2, 5);
    if (t11 == 1)
        goto LAB50;

LAB51:
LAB53:
LAB52:    xsi_set_current_line(73, ng0);

LAB59:
LAB54:    goto LAB41;

LAB44:    xsi_set_current_line(69, ng0);

LAB55:    xsi_set_current_line(69, ng0);
    t13 = ((char*)((ng3)));
    t14 = (t0 + 1228);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1780);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    goto LAB54;

LAB46:    xsi_set_current_line(70, ng0);

LAB56:    xsi_set_current_line(70, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 1228);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1780);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 1320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    goto LAB54;

LAB48:    xsi_set_current_line(71, ng0);

LAB57:    xsi_set_current_line(71, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 1228);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1780);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 1320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    goto LAB54;

LAB50:    xsi_set_current_line(72, ng0);

LAB58:    xsi_set_current_line(72, ng0);
    t3 = ((char*)((ng3)));
    t4 = (t0 + 1228);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1780);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    goto LAB54;

LAB60:    xsi_set_current_line(83, ng0);

LAB63:    xsi_set_current_line(84, ng0);
    t4 = ((char*)((ng12)));
    t13 = (t0 + 1228);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    xsi_set_current_line(85, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1780);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 564U);
    t3 = *((char **)t2);

LAB64:    t2 = ((char*)((ng1)));
    t11 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t11 == 1)
        goto LAB65;

LAB66:    t2 = ((char*)((ng12)));
    t11 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t11 == 1)
        goto LAB67;

LAB68:
LAB70:
LAB69:    xsi_set_current_line(96, ng0);

LAB74:
LAB71:    goto LAB62;

LAB65:    xsi_set_current_line(88, ng0);

LAB72:    xsi_set_current_line(89, ng0);
    t4 = ((char*)((ng12)));
    t13 = (t0 + 1504);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    xsi_set_current_line(90, ng0);
    t2 = ((char*)((ng12)));
    t4 = (t0 + 1688);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    goto LAB71;

LAB67:    xsi_set_current_line(92, ng0);

LAB73:    xsi_set_current_line(93, ng0);
    t4 = ((char*)((ng12)));
    t13 = (t0 + 1596);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    xsi_set_current_line(94, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 1688);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    goto LAB71;

LAB75:    xsi_set_current_line(103, ng0);

LAB78:    xsi_set_current_line(104, ng0);
    t13 = (t0 + 564U);
    t14 = *((char **)t13);

LAB79:    t13 = ((char*)((ng13)));
    t11 = xsi_vlog_unsigned_case_compare(t14, 5, t13, 5);
    if (t11 == 1)
        goto LAB80;

LAB81:    t2 = ((char*)((ng14)));
    t11 = xsi_vlog_unsigned_case_compare(t14, 5, t2, 5);
    if (t11 == 1)
        goto LAB82;

LAB83:    t2 = ((char*)((ng15)));
    t11 = xsi_vlog_unsigned_case_compare(t14, 5, t2, 5);
    if (t11 == 1)
        goto LAB84;

LAB85:
LAB87:
LAB86:    xsi_set_current_line(125, ng0);

LAB92:
LAB88:    goto LAB77;

LAB80:    xsi_set_current_line(105, ng0);

LAB89:    xsi_set_current_line(106, ng0);
    t15 = ((char*)((ng12)));
    t16 = (t0 + 1412);
    xsi_vlogvar_assign_value(t16, t15, 0, 0, 1);
    xsi_set_current_line(107, ng0);
    t2 = ((char*)((ng12)));
    t4 = (t0 + 1688);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(108, ng0);
    t2 = ((char*)((ng12)));
    t4 = (t0 + 1872);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    goto LAB88;

LAB82:    xsi_set_current_line(110, ng0);

LAB90:    xsi_set_current_line(111, ng0);
    t4 = ((char*)((ng12)));
    t13 = (t0 + 1228);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    xsi_set_current_line(112, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 1320);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 5);
    xsi_set_current_line(113, ng0);
    t2 = ((char*)((ng12)));
    t4 = (t0 + 1780);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(114, ng0);
    t2 = ((char*)((ng12)));
    t4 = (t0 + 1504);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(115, ng0);
    t2 = ((char*)((ng12)));
    t4 = (t0 + 1688);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(116, ng0);
    t2 = ((char*)((ng12)));
    t4 = (t0 + 1872);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    goto LAB88;

LAB84:    xsi_set_current_line(118, ng0);

LAB91:    xsi_set_current_line(119, ng0);
    t4 = ((char*)((ng12)));
    t13 = (t0 + 1228);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 1);
    xsi_set_current_line(120, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 1320);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 5);
    xsi_set_current_line(121, ng0);
    t2 = ((char*)((ng12)));
    t4 = (t0 + 1780);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(122, ng0);
    t2 = ((char*)((ng12)));
    t4 = (t0 + 1596);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(123, ng0);
    t2 = ((char*)((ng12)));
    t4 = (t0 + 1872);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    goto LAB88;

}


extern void work_m_00000000004230573760_0829766181_init()
{
	static char *pe[] = {(void *)A37_0};
	xsi_register_didat("work_m_00000000004230573760_0829766181", "isim/_tmp/work/m_00000000004230573760_0829766181.didat");
	xsi_register_executes(pe);
}
