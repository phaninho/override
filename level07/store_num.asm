gdb-peda$ pdisas store_number
Dump of assembler code for function store_number:
   0x08048630 <+0>:	push   ebp
   0x08048631 <+1>:	mov    ebp,esp
   0x08048633 <+3>:	sub    esp,0x28
   0x08048636 <+6>:	mov    DWORD PTR [ebp-0x10],0x0
   0x0804863d <+13>:	mov    DWORD PTR [ebp-0xc],0x0
   0x08048644 <+20>:	mov    eax,0x8048ad3
   0x08048649 <+25>:	mov    DWORD PTR [esp],eax
   0x0804864c <+28>:	call   0x8048470 <printf@plt>
                                                                       ;    number = 1    index = 4
   0x08048651 <+33>:	call   0x80485e7 <get_unum>
   0x08048656 <+38>:	mov    DWORD PTR [ebp-0x10],eax                ;   [ebp-0x10] = 1 (number)
   0x08048659 <+41>:	mov    eax,0x8048add
   0x0804865e <+46>:	mov    DWORD PTR [esp],eax
   0x08048661 <+49>:	call   0x8048470 <printf@plt>
   0x08048666 <+54>:	call   0x80485e7 <get_unum>
   0x0804866b <+59>:	mov    DWORD PTR [ebp-0xc],eax                 ;   [ebp-0xc] = 4 (index)
   0x0804866e <+62>:	mov    ecx,DWORD PTR [ebp-0xc]                 ;   ECX=4
   0x08048671 <+65>:	mov    edx,0xaaaaaaab
   0x08048676 <+70>:	mov    eax,ecx                                 ;   EAX=4  ECX=4
   0x08048678 <+72>:	mul    edx                                     ;   EDX=2  EAX=0xaaaaaaac EAX*EDX [4 * 0xaaaaaaab = 0x2aaaaaaac] (EDX=0x2 EAX=0xaaaaaaac)
                                                                       ;      -EDX conserve la partie haute du resultat et EAX le reste
   0x0804867a <+74>:	shr    edx,1                                   ;   EDX=1  2 >> 2 = 2/2 = 1
                                                                       ;      -decallage de 1 bit vers la droite sur EDX, reviens a  EDX/2
   0x0804867c <+76>:	mov    eax,edx                                 ;   EAX=1 EDX=1
   0x0804867e <+78>:	add    eax,eax                                 ;   EAX=2
   0x08048680 <+80>:	add    eax,edx                                 ;   EAX=3
   0x08048682 <+82>:	mov    edx,ecx                                 ;   EDX=4 EXC=4
   0x08048684 <+84>:	sub    edx,eax                                 ;   EDX=1
   0x08048686 <+86>:	test   edx,edx                                 ;       if edx==0 , set SF=1
   0x08048688 <+88>:	je     0x8048697 <store_number+103>            ;       if SF==1  , jmp
   0x0804868a <+90>:	mov    eax,DWORD PTR [ebp-0x10]                ;   EAX=1
   0x0804868d <+93>:	shr    eax,0x18                                ;   EAX=0  1 >> 24 = 1/16777216 = 0
   0x08048690 <+96>:	cmp    eax,0xb7                                ;      -cmp 0 a 183
   0x08048695 <+101>:	jne    0x80486c2 <store_number+146>            ;      -si != on saute
   0x08048697 <+103>:	mov    DWORD PTR [esp],0x8048ae6               ;       |
   0x0804869e <+110>:	call   0x80484c0 <puts@plt>                    ;       |
   0x080486a3 <+115>:	mov    DWORD PTR [esp],0x8048af8               ;       |
   0x080486aa <+122>:	call   0x80484c0 <puts@plt>                    ;       |
   0x080486af <+127>:	mov    DWORD PTR [esp],0x8048ae6               ;       |
   0x080486b6 <+134>:	call   0x80484c0 <puts@plt>                    ;       |
   0x080486bb <+139>:	mov    eax,0x1                                 ;      \| /
   0x080486c0 <+144>:	jmp    0x80486d5 <store_number+165>            ;       V
   0x080486c2 <+146>:	mov    eax,DWORD PTR [ebp-0xc]                 ;  EAX=4
   0x080486c5 <+149>:	shl    eax,0x2                                 ;  EAX=16  4 << 2 = 4 * 4 = 16  (== index * sizeof(int))
   0x080486c8 <+152>:	add    eax,DWORD PTR [ebp+0x8]                 ;  EAX=0xffffd544   0xffffd234 + 16  (addresse du pointeur + (offset * index))
   0x080486cb <+155>:	mov    edx,DWORD PTR [ebp-0x10]                ;  EDX=1   (nombre a stocker)
   0x080486ce <+158>:	mov    DWORD PTR [eax],edx                     ;  ptr[4] = 1
   0x080486d0 <+160>:	mov    eax,0x0                                 ;  EAX=0
   0x080486d5 <+165>:	leave                                          ;  EAX=0  ECX=4  EDX=1
   0x080486d6 <+166>:	ret
End of assembler dump.
