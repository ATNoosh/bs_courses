	.386p
	model flat
	ifndef	??version
	?debug	macro
	endm
	endif
	?debug	S "noname00.cpp"
	?debug	T "noname00.cpp"
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
_DATA	segment dword public use32 'DATA'
_DATA	ends
_BSS	segment dword public use32 'BSS'
_BSS	ends
$$BSYMS	segment byte public use32 'DEBSYM'
$$BSYMS	ends
$$BTYPES	segment byte public use32 'DEBTYP'
$$BTYPES	ends
$$BNAMES	segment byte public use32 'DEBNAM'
$$BNAMES	ends
$$BROWSE	segment byte public use32 'DEBSYM'
$$BROWSE	ends
$$BROWFILE	segment byte public use32 'DEBSYM'
$$BROWFILE	ends
DGROUP	group	_BSS,_DATA
_TEXT	segment dword public use32 'CODE'
_main	proc	near
?live1@0:
	?debug L 3
	push      ebp
	mov       ebp,esp
	?debug L 7
@1:
	mov	 ax,8
	?debug L 9
	call      _getch
	?debug L 10
@2:
	pop       ebp
	ret 
	?debug L 0
_main	endp
_TEXT	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	db	1
	db	0
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	db	2
	db	0
	db	0
	db	0
	dw	52
	dw	517
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dw	0
	dd	?patch1
	dd	?patch2
	dd	?patch3
	df	_main
	dw	0
	dw	4096
	dw	0
	dw	1
	dw	0
	dd	?patch4
	db	5
	db	95
	db	109
	db	97
	db	105
	db	110
?patch1	equ	@2-_main+2
?patch2	equ	0
?patch3	equ	@2-_main
	dw	2
	dw	6
$$BSYMS	ends
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
	public	_main
	extrn	_getch:near
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	16
	dw	4
	dw	117
	dw	0
	dw	0
	dw	2
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	2
	dw	45
	db	2
	db	254
	dw	322
	db	11
	db	34
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	4
	dw	0
	dw	16
	dw	4
	dw	113
	dw	0
	dw	0
	dw	3
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	2
	dw	57
	db	2
	db	254
	dw	310
	db	9
	db	61
	db	25
	db	2
	db	2
	db	2
	db	9
	db	2
	db	20
	db	2
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	21
	dw	0
	dw	16
	dw	4
	dw	18
	dw	0
	dw	0
	dw	4
	dw	0
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	2
	dw	63
	db	2
	db	254
	dw	311
	db	20
	db	0
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
	dw	46
	dw	0
	dw	?patch5
	dw	1
	db	2
	db	1
	db	8
	db	24
	db	6
	db	66
	db	67
	db	52
	db	46
	db	48
	db	48
?patch5	equ	13
$$BSYMS	ends
$$BROWSE	segment byte public use32 'DEBSYM'
	dw	0
	dw	0
	dw	0
	db	1
	dw	3
	db	0
$$BROWSE	ends
$$BSYMS	segment byte public use32 'DEBSYM'
?patch4	equ	62
$$BSYMS	ends
$$BROWFILE	segment byte public use32 'DEBSYM'
	dw	5
	dw	0
	dw	6
	dw	0
	dw	7
	dw	0
	dw	8
	dw	0
	dw	9
	dw	0
	dw	10
	dw	0
$$BROWFILE	ends
$$BTYPES	segment byte public use32 'DEBTYP'
	db        2,0,0,0,14,0,8,0,3,0,0,0,0,0,0,0
	db        1,16,0,0,4,0,1,2,0,0,14,0,8,0,116,0
	db        0,0,0,0,0,0,3,16,0,0,4,0,1,2,0,0
$$BTYPES	ends
$$BNAMES	segment byte public use32 'DEBNAM'
	db	4,'main'
	db	6,'size_t'
	db	6,'wint_t'
	db	6,'fpos_t'
	db	12,'noname00.cpp'
	db	28,'D:C LANGUAGE\INCLUDE\STDIO.H'
	db	28,'D:C LANGUAGE\INCLUDE\_defs.h'
	db	29,'D:C LANGUAGE\INCLUDE\_nfile.h'
	db	28,'D:C LANGUAGE\INCLUDE\_null.h'
	db	28,'D:C LANGUAGE\INCLUDE\CONIO.H'
$$BNAMES	ends
	?debug	D "D:C LANGUAGE\INCLUDE\CONIO.H" 8825 10304
	?debug	D "D:C LANGUAGE\INCLUDE\_null.h" 8825 10304
	?debug	D "D:C LANGUAGE\INCLUDE\_nfile.h" 8825 10304
	?debug	D "D:C LANGUAGE\INCLUDE\_defs.h" 8825 10304
	?debug	D "D:C LANGUAGE\INCLUDE\STDIO.H" 8825 10304
	?debug	D "noname00.cpp" 11316 34848
	end
