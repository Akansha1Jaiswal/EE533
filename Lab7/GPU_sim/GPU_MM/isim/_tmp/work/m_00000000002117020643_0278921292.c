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
static const char *ng0 = "C:/Documents and Settings/student/My Documents/GPU_MM/register_file.v";
static int ng1[] = {0, 0};
static int ng2[] = {16, 0};
static unsigned int ng3[] = {0U, 0U, 0U, 0U};
static int ng4[] = {1, 0};
static unsigned int ng5[] = {0U, 0U};



static void A22_0(char *t0)
{
    char t12[8];
    char t15[8];
    char t16[8];
    char t53[8];
    char t84[8];
    char t85[8];
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
    char *t11;
    char *t13;
    char *t14;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;
    int t28;
    char *t29;
    unsigned int t30;
    int t31;
    int t32;
    unsigned int t33;
    unsigned int t34;
    int t35;
    int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
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
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    char *t86;
    char *t87;
    char *t88;
    char *t89;
    char *t90;
    char *t91;
    char *t92;
    char *t93;
    unsigned int t94;
    char *t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    int t99;
    int t100;

LAB0:    t1 = (t0 + 2236U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(22, ng0);
    t2 = (t0 + 2800);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(22, ng0);

LAB5:    xsi_set_current_line(23, ng0);
    t3 = (t0 + 652U);
    t4 = *((char **)t3);
    t3 = (t4 + 4U);
    t5 = *((unsigned int *)t3);
    t6 = (~(t5));
    t7 = *((unsigned int *)t4);
    t8 = (t7 & t6);
    t9 = (t8 != 0);
    if (t9 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(27, ng0);
    t2 = (t0 + 1180U);
    t3 = *((char **)t2);
    memset(t12, 0, 8);
    t2 = (t12 + 4U);
    t4 = (t3 + 4U);
    t5 = *((unsigned int *)t4);
    t6 = (~(t5));
    t7 = *((unsigned int *)t3);
    t8 = (t7 & t6);
    t9 = (t8 & 1U);
    if (t9 != 0)
        goto LAB15;

LAB16:    if (*((unsigned int *)t4) != 0)
        goto LAB17;

LAB18:    t10 = (t12 + 4U);
    t27 = *((unsigned int *)t12);
    t30 = *((unsigned int *)t10);
    t33 = (t27 || t30);
    if (t33 > 0)
        goto LAB19;

LAB20:    memcpy(t53, t12, 8);

LAB21:    t26 = (t53 + 4U);
    t78 = *((unsigned int *)t26);
    t79 = (~(t78));
    t80 = *((unsigned int *)t53);
    t81 = (t80 & t79);
    t82 = (t81 != 0);
    if (t82 > 0)
        goto LAB33;

LAB34:
LAB35:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(23, ng0);

LAB9:    xsi_set_current_line(24, ng0);
    xsi_set_current_line(24, ng0);
    t10 = ((char*)((ng1)));
    t11 = (t0 + 1760);
    xsi_vlogvar_assign_value(t11, t10, 0, 0, 32);

LAB10:    t2 = (t0 + 1760);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t10 = ((char*)((ng2)));
    memset(t12, 0, 8);
    xsi_vlog_signed_less(t12, 32, t4, 32, t10, 32);
    t11 = (t12 + 4U);
    t5 = *((unsigned int *)t11);
    t6 = (~(t5));
    t7 = *((unsigned int *)t12);
    t8 = (t7 & t6);
    t9 = (t8 != 0);
    if (t9 > 0)
        goto LAB11;

LAB12:    goto LAB8;

LAB11:    xsi_set_current_line(25, ng0);
    t13 = ((char*)((ng3)));
    t14 = (t0 + 1668);
    t17 = (t0 + 1668);
    t18 = (t17 + 40U);
    t19 = *((char **)t18);
    t20 = (t0 + 1668);
    t21 = (t20 + 36U);
    t22 = *((char **)t21);
    t23 = (t0 + 1760);
    t24 = (t23 + 32U);
    t25 = *((char **)t24);
    xsi_vlog_generic_convert_array_indices(t15, t16, t19, t22, 2, 1, t25, 32, 1);
    t26 = (t15 + 4U);
    t27 = *((unsigned int *)t26);
    t28 = (!(t27));
    t29 = (t16 + 4U);
    t30 = *((unsigned int *)t29);
    t31 = (!(t30));
    t32 = (t28 && t31);
    if (t32 == 1)
        goto LAB13;

LAB14:    xsi_set_current_line(24, ng0);
    t2 = (t0 + 1760);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t10 = ((char*)((ng4)));
    memset(t12, 0, 8);
    xsi_vlog_signed_add(t12, 32, t4, 32, t10, 32);
    t11 = (t0 + 1760);
    xsi_vlogvar_assign_value(t11, t12, 0, 0, 32);
    goto LAB10;

LAB13:    t33 = *((unsigned int *)t15);
    t34 = *((unsigned int *)t16);
    t35 = (t33 - t34);
    t36 = (t35 + 1);
    xsi_vlogvar_generic_wait_assign_value(t14, t13, 2, 0, *((unsigned int *)t16), t36, 0LL);
    goto LAB14;

LAB15:    *((unsigned int *)t12) = 1;
    goto LAB18;

LAB17:    *((unsigned int *)t12) = 1;
    *((unsigned int *)t2) = 1;
    goto LAB18;

LAB19:    t11 = (t0 + 1004U);
    t13 = *((char **)t11);
    t11 = ((char*)((ng5)));
    memset(t15, 0, 8);
    t14 = (t15 + 4U);
    t17 = (t13 + 4U);
    t18 = (t11 + 4U);
    t34 = *((unsigned int *)t13);
    t37 = *((unsigned int *)t11);
    t38 = (t34 ^ t37);
    t39 = *((unsigned int *)t17);
    t40 = *((unsigned int *)t18);
    t41 = (t39 ^ t40);
    t42 = (t38 | t41);
    t43 = *((unsigned int *)t17);
    t44 = *((unsigned int *)t18);
    t45 = (t43 | t44);
    t46 = (~(t45));
    t47 = (t42 & t46);
    if (t47 != 0)
        goto LAB23;

LAB22:    if (t45 != 0)
        goto LAB24;

LAB25:    memset(t16, 0, 8);
    t19 = (t16 + 4U);
    t20 = (t15 + 4U);
    t48 = *((unsigned int *)t20);
    t49 = (~(t48));
    t50 = *((unsigned int *)t15);
    t51 = (t50 & t49);
    t52 = (t51 & 1U);
    if (t52 != 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t20) != 0)
        goto LAB28;

LAB29:    t54 = *((unsigned int *)t12);
    t55 = *((unsigned int *)t16);
    t56 = (t54 & t55);
    *((unsigned int *)t53) = t56;
    t21 = (t12 + 4U);
    t22 = (t16 + 4U);
    t23 = (t53 + 4U);
    t57 = *((unsigned int *)t21);
    t58 = *((unsigned int *)t22);
    t59 = (t57 | t58);
    *((unsigned int *)t23) = t59;
    t60 = *((unsigned int *)t23);
    t61 = (t60 != 0);
    if (t61 == 1)
        goto LAB30;

LAB31:
LAB32:    goto LAB21;

LAB23:    *((unsigned int *)t15) = 1;
    goto LAB25;

LAB24:    *((unsigned int *)t15) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB25;

LAB26:    *((unsigned int *)t16) = 1;
    goto LAB29;

LAB28:    *((unsigned int *)t16) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB29;

LAB30:    t62 = *((unsigned int *)t53);
    t63 = *((unsigned int *)t23);
    *((unsigned int *)t53) = (t62 | t63);
    t24 = (t12 + 4U);
    t25 = (t16 + 4U);
    t64 = *((unsigned int *)t12);
    t65 = (~(t64));
    t66 = *((unsigned int *)t24);
    t67 = (~(t66));
    t68 = *((unsigned int *)t16);
    t69 = (~(t68));
    t70 = *((unsigned int *)t25);
    t71 = (~(t70));
    t28 = (t65 & t67);
    t31 = (t69 & t71);
    t72 = (~(t28));
    t73 = (~(t31));
    t74 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t74 & t72);
    t75 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t75 & t73);
    t76 = *((unsigned int *)t53);
    *((unsigned int *)t53) = (t76 & t72);
    t77 = *((unsigned int *)t53);
    *((unsigned int *)t53) = (t77 & t73);
    goto LAB32;

LAB33:    xsi_set_current_line(27, ng0);

LAB36:    xsi_set_current_line(28, ng0);
    t29 = (t0 + 1092U);
    t83 = *((char **)t29);
    t29 = (t0 + 1668);
    t86 = (t0 + 1668);
    t87 = (t86 + 40U);
    t88 = *((char **)t87);
    t89 = (t0 + 1668);
    t90 = (t89 + 36U);
    t91 = *((char **)t90);
    t92 = (t0 + 1004U);
    t93 = *((char **)t92);
    xsi_vlog_generic_convert_array_indices(t84, t85, t88, t91, 2, 1, t93, 4, 2);
    t92 = (t84 + 4U);
    t94 = *((unsigned int *)t92);
    t32 = (!(t94));
    t95 = (t85 + 4U);
    t96 = *((unsigned int *)t95);
    t35 = (!(t96));
    t36 = (t32 && t35);
    if (t36 == 1)
        goto LAB37;

LAB38:    goto LAB35;

LAB37:    t97 = *((unsigned int *)t84);
    t98 = *((unsigned int *)t85);
    t99 = (t97 - t98);
    t100 = (t99 + 1);
    xsi_vlogvar_generic_wait_assign_value(t29, t83, 2, 0, *((unsigned int *)t85), t100, 0LL);
    goto LAB38;

}

static void C33_1(char *t0)
{
    char t5[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
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

LAB0:    t1 = (t0 + 2364U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1668);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t6 = (t0 + 1668);
    t7 = (t6 + 40U);
    t8 = *((char **)t7);
    t9 = (t0 + 1668);
    t10 = (t9 + 36U);
    t11 = *((char **)t10);
    t12 = (t0 + 740U);
    t13 = *((char **)t12);
    xsi_vlog_generic_get_array_select_value(t5, 64, t4, t8, t11, 2, 1, t13, 4, 2);
    t12 = (t0 + 2868);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    xsi_vlog_bit_copy(t17, 0, t5, 0, 64);
    xsi_driver_vfirst_trans(t12, 0, 63);
    t18 = (t0 + 2808);
    *((int *)t18) = 1;

LAB1:    return;
}

static void C34_2(char *t0)
{
    char t5[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
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

LAB0:    t1 = (t0 + 2492U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1668);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t6 = (t0 + 1668);
    t7 = (t6 + 40U);
    t8 = *((char **)t7);
    t9 = (t0 + 1668);
    t10 = (t9 + 36U);
    t11 = *((char **)t10);
    t12 = (t0 + 828U);
    t13 = *((char **)t12);
    xsi_vlog_generic_get_array_select_value(t5, 64, t4, t8, t11, 2, 1, t13, 4, 2);
    t12 = (t0 + 2904);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    xsi_vlog_bit_copy(t17, 0, t5, 0, 64);
    xsi_driver_vfirst_trans(t12, 0, 63);
    t18 = (t0 + 2816);
    *((int *)t18) = 1;

LAB1:    return;
}

static void C35_3(char *t0)
{
    char t5[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
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

LAB0:    t1 = (t0 + 2620U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1668);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t6 = (t0 + 1668);
    t7 = (t6 + 40U);
    t8 = *((char **)t7);
    t9 = (t0 + 1668);
    t10 = (t9 + 36U);
    t11 = *((char **)t10);
    t12 = (t0 + 916U);
    t13 = *((char **)t12);
    xsi_vlog_generic_get_array_select_value(t5, 64, t4, t8, t11, 2, 1, t13, 4, 2);
    t12 = (t0 + 2940);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    xsi_vlog_bit_copy(t17, 0, t5, 0, 64);
    xsi_driver_vfirst_trans(t12, 0, 63);
    t18 = (t0 + 2824);
    *((int *)t18) = 1;

LAB1:    return;
}


extern void work_m_00000000002117020643_0278921292_init()
{
	static char *pe[] = {(void *)A22_0,(void *)C33_1,(void *)C34_2,(void *)C35_3};
	xsi_register_didat("work_m_00000000002117020643_0278921292", "isim/_tmp/work/m_00000000002117020643_0278921292.didat");
	xsi_register_executes(pe);
}
