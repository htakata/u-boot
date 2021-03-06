/*
 * Copyright (C) 2010 Yoshinori Sato <ysato@users.sourceforge.jp>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <command.h>
#include <asm/processor.h>
#include <asm/io.h>

int checkcpu(void)
{
	puts("CPU: RX600\n");
	return 0;
}

int cpu_init(void)
{
	return 0;
}

int cleanup_before_linux(void)
{
	disable_interrupts();
	return 0;
}

int do_reset(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	disable_interrupts();
	reset_cpu(0);
	return 0;
}

void flush_cache(unsigned long addr, unsigned long size)
{

}

void icache_enable(void)
{
}

void icache_disable(void)
{
}

int icache_status(void)
{
	return 0;
}

void dcache_enable(void)
{
}

void dcache_disable(void)
{
}

int dcache_status(void)
{
	return 0;
}

int cpu_eth_init(bd_t *bis)
{
#if defined(CONFIG_SH_ETHER)
#if defined(CONFIG_RX62N_RMII)
	outb(0x82, 0x8c10e);
	outb(inb(0x8c065) | 0x10, 0x8c065);
	outb(inb(0x8c067) | 0xf2, 0x8c067);
	outb(inb(0x8c068) | 0x08, 0x8c068);
#endif
	sh_eth_initialize(bis);
#endif
	return 0;
}
