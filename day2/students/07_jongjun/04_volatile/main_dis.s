
main:	file format mach-o arm64


Disassembly of section __TEXT,__text:

0000000100003f44 <_main>:
100003f44: ff 83 00 d1 	sub	sp, sp, #32
100003f48: fd 7b 01 a9 	stp	x29, x30, [sp, #16]
100003f4c: fd 43 00 91 	add	x29, sp, #16
100003f50: e0 02 00 30 	adr	x0, #93
100003f54: 1f 20 03 d5 	nop
100003f58: 10 00 00 94 	bl	0x100003f98 <_puts+0x100003f98>
100003f5c: 08 01 80 52 	mov	w8, #8
100003f60: a8 c3 1f b8 	stur	w8, [x29, #-4]
100003f64: a8 c3 5f b8 	ldur	w8, [x29, #-4]
100003f68: 08 09 00 11 	add	w8, w8, #2
100003f6c: e8 03 00 f9 	str	x8, [sp]
100003f70: a0 01 00 10 	adr	x0, #52
100003f74: 1f 20 03 d5 	nop
100003f78: 05 00 00 94 	bl	0x100003f8c <_puts+0x100003f8c>
100003f7c: 00 00 80 52 	mov	w0, #0
100003f80: fd 7b 41 a9 	ldp	x29, x30, [sp, #16]
100003f84: ff 83 00 91 	add	sp, sp, #32
100003f88: c0 03 5f d6 	ret

Disassembly of section __TEXT,__stubs:

0000000100003f8c <__stubs>:
100003f8c: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0x4>
100003f90: 10 02 40 f9 	ldr	x16, [x16]
100003f94: 00 02 1f d6 	br	x16
100003f98: 10 00 00 b0 	adrp	x16, 0x100004000 <__stubs+0x10>
100003f9c: 10 06 40 f9 	ldr	x16, [x16, #8]
100003fa0: 00 02 1f d6 	br	x16
