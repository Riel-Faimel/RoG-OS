./build/arch/mod_no_tools.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000100000 <_ZN8._anon_011kmalloc_getEm>:
push   %rbp
mov    %rsp,%rbp
mov    %rdi,-0x8(%rbp)
mov    %rsi,-0x10(%rbp)
ud2
000000000010000e <_ZN8._anon_012kmalloc_backEPv>:
push   %rbp
mov    %rsp,%rbp
mov    %rdi,-0x8(%rbp)
mov    %rsi,-0x10(%rbp)
cmpq   $0x0,-0x10(%rbp)
pop    %rbp
ret

0000000000100021 <_Znwm>:
push   %rbp
mov    %rsp,%rbp
sub    $0x8,%rsp
mov    %rdi,-0x8(%rbp)
mov    -0x8(%rbp),%rax
mov    %rax,%rsi
mov    $0x0,%edi
call   100000 <_ZN8._anon_011kmalloc_getEm>
leave
ret

0000000000100040 <_ZdlPv>:
push   %rbp
mov    %rsp,%rbp
sub    $0x8,%rsp
mov    %rdi,-0x8(%rbp)
mov    -0x8(%rbp),%rax
mov    %rax,%rsi
mov    $0x0,%edi
call   10000e <_ZN8._anon_012kmalloc_backEPv>
nop
leave
ret

0000000000100060 <_ZN15FixedMemoryPoolC1E26MemoryManager_AddressValue23MemoryManager_SizeValue23MemoryManager_TailChain>:
push   %rbp
mov    %rsp,%rbp
sub    $0x30,%rsp
mov    %rdi,-0x18(%rbp)
mov    %rsi,%rax
mov    %rdx,%rcx
mov    %rax,%rax
mov    $0x0,%edx
mov    %rcx,%rdx
mov    %rax,-0x30(%rbp)
mov    %rdx,-0x28(%rbp)
mov    0x20(%rbp),%rdx
mov    -0x18(%rbp),%rax
mov    %rdx,(%rax)
mov    0x18(%rbp),%rdx
mov    -0x18(%rbp),%rax
mov    %rdx,0x8(%rax)
mov    0x10(%rbp),%rdx
mov    -0x18(%rbp),%rax
mov    %rdx,0x10(%rax)
mov    0x28(%rbp),%edx
mov    -0x18(%rbp),%rax
mov    %edx,0x18(%rax)
mov    0x30(%rbp),%edx
mov    -0x18(%rbp),%rax
mov    %edx,0x1c(%rax)
mov    0x3c(%rbp),%edx
mov    -0x18(%rbp),%rax
mov    %edx,0x20(%rax)
mov    0x34(%rbp),%edx
mov    -0x18(%rbp),%rax
mov    %edx,0x24(%rax)
mov    0x38(%rbp),%edx
mov    -0x18(%rbp),%rax
mov    %edx,0x28(%rax)
mov    -0x18(%rbp),%rax
movb   $0x0,0x2c(%rax)
mov    -0x18(%rbp),%rax
movb   $0x0,0x2d(%rax)
mov    -0x18(%rbp),%rax
lea    0x30(%rax),%rcx
mov    -0x28(%rbp),%edx
mov    -0x30(%rbp),%rax
mov    %rax,%rsi
mov    %rcx,%rdi
call   100104 <_ZN15FixedMemoryPoolC1E26MemoryManager_AddressValue23MemoryManager_SizeValue23MemoryManager_TailChain+0xa4>
mov    -0x18(%rbp),%rax
mov    (%rax),%rax
mov    0x2c(%rbp),%edx
mov    %edx,(%rax)
movl   $0x1,-0x4(%rbp)
jmp    100137 <_ZN15FixedMemoryPoolC1E26MemoryManager_AddressValue23MemoryManager_SizeValue23MemoryManager_TailChain+0xd7>
mov    -0x18(%rbp),%rax
mov    (%rax),%rax
mov    -0x4(%rbp),%edx
movslq %edx,%rdx
shl    $0x2,%rdx
add    %rdx,%rax
movl   $0x0,(%rax)
addl   $0x1,-0x4(%rbp)
mov    -0x18(%rbp),%rax
mov    0x24(%rax),%eax
mov    -0x4(%rbp),%edx
cmp    %eax,%edx
jb     100119 <_ZN15FixedMemoryPoolC1E26MemoryManager_AddressValue23MemoryManager_SizeValue23MemoryManager_TailChain+0xb9>
movl   $0x0,-0x8(%rbp)
jmp    100175 <_ZN15FixedMemoryPoolC1E26MemoryManager_AddressValue23MemoryManager_SizeValue23MemoryManager_TailChain+0x115>
mov    -0x18(%rbp),%rax
mov    0x8(%rax),%rax
mov    -0x8(%rbp),%edx
movslq %edx,%rdx
shl    $0x4,%rdx
add    %rdx,%rax
movq   $0x0,(%rax)
movl   $0x0,0x8(%rax)
addl   $0x1,-0x8(%rbp)
mov    -0x18(%rbp),%rax
mov    0x28(%rax),%eax
mov    -0x8(%rbp),%edx
cmp    %eax,%edx
jb     10014e <_ZN15FixedMemoryPoolC1E26MemoryManager_AddressValue23MemoryManager_SizeValue23MemoryManager_TailChain+0xee>
nop
nop
leave
ret
nop
0000000000100188 <_ZN15FixedMemoryPool9addr_itemEj>:
push   %rbp
mov    %rsp,%rbp
mov    %rdi,-0x18(%rbp)
mov    %esi,-0x1c(%rbp)
movl   $0x0,-0x4(%rbp)
movl   $0x0,-0x8(%rbp)
jmp    1001c0 <_ZN15FixedMemoryPool9addr_itemEj+0x38>
mov    -0x18(%rbp),%rax
mov    (%rax),%rax
mov    -0x8(%rbp),%edx
movslq %edx,%rdx
shl    $0x2,%rdx
add    %rdx,%rax
mov    (%rax),%eax
add    %eax,-0x4(%rbp)
addl   $0x1,-0x8(%rbp)
mov    -0x8(%rbp),%eax
cmp    -0x1c(%rbp),%eax
jb     1001a3 <_ZN15FixedMemoryPool9addr_itemEj+0x1b>
mov    -0x18(%rbp),%rax
mov    0x1c(%rax),%eax
mov    -0x4(%rbp),%edx
imul   %edx,%eax
mov    %eax,-0x4(%rbp)
mov    -0x18(%rbp),%rax
mov    0x10(%rax),%rdx
mov    -0x4(%rbp),%eax
add    %rdx,%rax
pop    %rbp
ret

00000000001001e8 <_ZN15FixedMemoryPool11search_itemEj>:
push   %rbp
mov    %rsp,%rbp
mov    %rdi,-0x18(%rbp)
mov    %esi,-0x1c(%rbp)
movl   $0x2,-0x4(%rbp)
jmp    10021d <_ZN15FixedMemoryPool11search_itemEj+0x35>
mov    -0x18(%rbp),%rax
mov    (%rax),%rax
mov    -0x4(%rbp),%edx
shl    $0x2,%rdx
add    %rdx,%rax
mov    (%rax),%eax
cmp    %eax,-0x1c(%rbp)
jae    100219 <_ZN15FixedMemoryPool11search_itemEj+0x31>
mov    -0x4(%rbp),%eax
jmp    100256 <_ZN15FixedMemoryPool11search_itemEj+0x6e>
addl   $0x2,-0x4(%rbp)
mov    -0x18(%rbp),%rax
mov    (%rax),%rax
mov    -0x4(%rbp),%edx
shl    $0x2,%rdx
add    %rdx,%rax
mov    (%rax),%eax
test   %eax,%eax
jne    1001fc <_ZN15FixedMemoryPool11search_itemEj+0x14>
mov    -0x18(%rbp),%rax
mov    (%rax),%rax
mov    (%rax),%eax
cmp    %eax,-0x1c(%rbp)
jae    100249 <_ZN15FixedMemoryPool11search_itemEj+0x61>
mov    $0x0,%eax
jmp    100256 <_ZN15FixedMemoryPool11search_itemEj+0x6e>
mov    -0x18(%rbp),%rax
movb   $0xff,0x2c(%rax)
mov    $0x0,%eax
pop    %rbp
ret

0000000000100258 <_ZN15FixedMemoryPool11extern_itemEjj>:
push   %rbp
mov    %rsp,%rbp
mov    %rdi,-0x8(%rbp)
mov    %esi,-0xc(%rbp)
mov    %edx,-0x10(%rbp)
mov    -0x8(%rbp),%rax
mov    (%rax),%rax
mov    -0xc(%rbp),%edx
add    $0x1,%edx
mov    %edx,%edx
shl    $0x2,%rdx
add    %rdx,%rax
mov    (%rax),%eax
cmp    %eax,-0x10(%rbp)
jb     10028d <_ZN15FixedMemoryPool11extern_itemEjj+0x35>
mov    -0x8(%rbp),%rax
movb   $0xff,0x2c(%rax)
jmp    1002ec <_ZN15FixedMemoryPool11extern_itemEjj+0x94>
mov    -0x8(%rbp),%rax
mov    (%rax),%rax
mov    -0xc(%rbp),%edx
shl    $0x2,%rdx
add    %rdx,%rax
mov    (%rax),%ecx
mov    -0x8(%rbp),%rax
mov    (%rax),%rax
mov    -0xc(%rbp),%edx
shl    $0x2,%rdx
add    %rdx,%rax
mov    -0x10(%rbp),%edx
add    %ecx,%edx
mov    %edx,(%rax)
mov    -0x8(%rbp),%rax
mov    (%rax),%rax
mov    -0xc(%rbp),%edx
sub    $0x1,%edx
mov    %edx,%edx
shl    $0x2,%rdx
add    %rdx,%rax
mov    (%rax),%eax
mov    -0x8(%rbp),%rdx
mov    (%rdx),%rdx
mov    -0xc(%rbp),%ecx
sub    $0x1,%ecx
mov    %ecx,%ecx
shl    $0x2,%rcx
add    %rcx,%rdx
sub    -0x10(%rbp),%eax
mov    %eax,(%rdx)
nop
pop    %rbp
ret

00000000001002ee <_ZN15FixedMemoryPool13compress_itemEjj>:
push   %rbp
mov    %rsp,%rbp
mov    %rdi,-0x8(%rbp)
mov    %esi,-0xc(%rbp)
mov    %edx,-0x10(%rbp)
mov    -0x8(%rbp),%rax
mov    (%rax),%rax
mov    -0xc(%rbp),%edx
shl    $0x2,%rdx
add    %rdx,%rax
mov    (%rax),%eax
cmp    %eax,-0x10(%rbp)
jb     10031e <_ZN15FixedMemoryPool13compress_itemEjj+0x30>
mov    -0x8(%rbp),%rax
movb   $0xff,0x2c(%rax)
jmp    10037d <_ZN15FixedMemoryPool13compress_itemEjj+0x8f>
mov    -0x8(%rbp),%rax
mov    (%rax),%rax
mov    -0xc(%rbp),%edx
shl    $0x2,%rdx
add    %rdx,%rax
mov    (%rax),%eax
mov    -0x8(%rbp),%rdx
mov    (%rdx),%rdx
mov    -0xc(%rbp),%ecx
shl    $0x2,%rcx
add    %rcx,%rdx
sub    -0x10(%rbp),%eax
mov    %eax,(%rdx)
mov    -0x8(%rbp),%rax
mov    (%rax),%rax
mov    -0xc(%rbp),%edx
add    $0x1,%edx
mov    %edx,%edx
shl    $0x2,%rdx
add    %rdx,%rax
mov    (%rax),%ecx
mov    -0x8(%rbp),%rax
mov    (%rax),%rax
mov    -0xc(%rbp),%edx
add    $0x1,%edx
mov    %edx,%edx
shl    $0x2,%rdx
add    %rdx,%rax
mov    -0x10(%rbp),%edx
add    %ecx,%edx
mov    %edx,(%rax)
nop
pop    %rbp
ret
nop

0000000000100380 <_ZN15FixedMemoryPool13turncate_itemEjjj>:
push   %rbp
mov    %rsp,%rbp
mov    %rdi,-0x8(%rbp)
mov    %esi,-0xc(%rbp)
mov    %edx,-0x10(%rbp)
mov    %ecx,-0x14(%rbp)
nop
pop    %rbp
ret
0000000000100394 <_ZN15FixedMemoryPool11delete_itemEj>:
push   %rbp
mov    %rsp,%rbp
mov    %rdi,-0x8(%rbp)
mov    %esi,-0xc(%rbp)
nop
pop    %rbp
ret

00000000001003a2 <_ZN15FixedMemoryPool18reg2_ptr2size_listEPvj>:
push   %rbp
mov    %rsp,%rbp
sub    $0x40,%rsp
mov    %rdi,-0x28(%rbp)
mov    %rsi,-0x30(%rbp)
mov    %edx,-0x34(%rbp)
mov    -0x28(%rbp),%rax
mov    0x8(%rax),%rax
mov    %rax,-0x8(%rbp)
jmp    1003eb <_ZN15FixedMemoryPool18reg2_ptr2size_listEPvj+0x49>
mov    -0x8(%rbp),%rax
mov    (%rax),%rax
test   %rax,%rax
jne    1003e6 <_ZN15FixedMemoryPool18reg2_ptr2size_listEPvj+0x44>
mov    -0x8(%rbp),%rax
mov    -0x30(%rbp),%rdx
mov    %rdx,(%rax)
mov    -0x8(%rbp),%rax
mov    -0x34(%rbp),%edx
mov    %edx,0x8(%rax)
jmp    100409 <_ZN15FixedMemoryPool18reg2_ptr2size_listEPvj+0x67>
addq   $0x10,-0x8(%rbp)
mov    -0x28(%rbp),%rax
mov    0x8(%rax),%rdx
mov    -0x28(%rbp),%rax
mov    0x28(%rax),%eax
mov    %eax,%eax
shl    $0x4,%rax
add    %rdx,%rax
cmp    %rax,-0x8(%rbp)
jb     1003c3 <_ZN15FixedMemoryPool18reg2_ptr2size_listEPvj+0x21>
mov    -0x28(%rbp),%rax
movb   $0x0,0x2d(%rax)
mov    -0x30(%rbp),%rax
mov    %rax,-0x20(%rbp)
mov    -0x34(%rbp),%eax
mov    %eax,-0x18(%rbp)
mov    -0x28(%rbp),%rax
lea    0x30(%rax),%rdi
lea    -0x20(%rbp),%rax
mov    $0x1,%ecx
mov    %rax,%rdx
mov    $0x0,%esi
call   10043d <_ZN15FixedMemoryPool18reg2_ptr2size_listEPvj+0x9b>
nop
leave
ret

0000000000100440 <_ZN15FixedMemoryPool19clear_ptr2size_listEPNS_8ptr2sizeE>:
push   %rbp
mov    %rsp,%rbp
mov    %rdi,-0x18(%rbp)
mov    %rsi,-0x20(%rbp)
mov    -0x18(%rbp),%rax
mov    0x8(%rax),%rax
mov    %rax,-0x8(%rbp)
jmp    100481 <_ZN15FixedMemoryPool19clear_ptr2size_listEPNS_8ptr2sizeE+0x41>
mov    -0x20(%rbp),%rax
cmp    -0x8(%rbp),%rax
jne    10047c <_ZN15FixedMemoryPool19clear_ptr2size_listEPNS_8ptr2sizeE+0x3c>
mov    -0x8(%rbp),%rax
movq   $0x0,(%rax)
mov    -0x8(%rbp),%rax
movl   $0x0,0x8(%rax)
jmp    1004b2 <_ZN15FixedMemoryPool19clear_ptr2size_listEPNS_8ptr2sizeE+0x72>
addq   $0x10,-0x8(%rbp)
mov    -0x18(%rbp),%rax
mov    0x8(%rax),%rdx
mov    -0x18(%rbp),%rax
mov    0x28(%rax),%eax
mov    %eax,%eax
shl    $0x4,%rax
add    %rdx,%rax
cmp    %rax,-0x8(%rbp)
jb     10045a <_ZN15FixedMemoryPool19clear_ptr2size_listEPNS_8ptr2sizeE+0x1a>
mov    -0x20(%rbp),%rax
cmp    -0x8(%rbp),%rax
jne    10045a <_ZN15FixedMemoryPool19clear_ptr2size_listEPNS_8ptr2sizeE+0x1a>
mov    -0x18(%rbp),%rax
movb   $0xff,0x2c(%rax)
nop
pop    %rbp
ret

00000000001004b4 <_ZN15FixedMemoryPool8allocateEjj>:
push   %rbp
mov    %rsp,%rbp
sub    $0x20,%rsp
mov    %rdi,-0x18(%rbp)
mov    %esi,-0x1c(%rbp)
mov    %edx,-0x20(%rbp)
mov    -0x18(%rbp),%rax
mov    0x1c(%rax),%edx
mov    -0x1c(%rbp),%eax
add    %edx,%eax
lea    -0x1(%rax),%ecx
mov    -0x18(%rbp),%rax
mov    0x1c(%rax),%edi
mov    %ecx,%eax
mov    $0x0,%edx
div    %edi
mov    %eax,-0xc(%rbp)
mov    -0xc(%rbp),%edx
mov    -0x18(%rbp),%rax
mov    %edx,%esi
mov    %rax,%rdi
call   1004f9 <_ZN15FixedMemoryPool8allocateEjj+0x45>
mov    %eax,-0x10(%rbp)
cmpl   $0x0,-0x10(%rbp)
jne    100535 <_ZN15FixedMemoryPool8allocateEjj+0x81>
mov    -0x18(%rbp),%rax
mov    0x20(%rax),%edx
mov    -0xc(%rbp),%ecx
mov    -0x10(%rbp),%esi
mov    -0x18(%rbp),%rax
mov    %rax,%rdi
call   10051b <_ZN15FixedMemoryPool8allocateEjj+0x67>
mov    -0x10(%rbp),%eax
lea    0x1(%rax),%edx
mov    -0x18(%rbp),%rax
mov    %edx,%esi
mov    %rax,%rdi
call   10052f <_ZN15FixedMemoryPool8allocateEjj+0x7b>
mov    %rax,-0x8(%rbp)
jmp    100564 <_ZN15FixedMemoryPool8allocateEjj+0xb0>
mov    -0x10(%rbp),%eax
lea    0x1(%rax),%edx
mov    -0x18(%rbp),%rax
mov    %edx,%esi
mov    %rax,%rdi
call   100549 <_ZN15FixedMemoryPool8allocateEjj+0x95>
mov    %rax,-0x8(%rbp)
mov    -0x10(%rbp),%eax
lea    -0x1(%rax),%ecx
mov    -0xc(%rbp),%edx
mov    -0x18(%rbp),%rax
mov    %ecx,%esi
mov    %rax,%rdi
call   100564 <_ZN15FixedMemoryPool8allocateEjj+0xb0>
mov    -0xc(%rbp),%edx
mov    -0x8(%rbp),%rcx
mov    -0x18(%rbp),%rax
mov    %rcx,%rsi
mov    %rax,%rdi
call   10057a <_ZN15FixedMemoryPool8allocateEjj+0xc6>
mov    -0x8(%rbp),%rax
leave
ret

0000000000100580 <_ZN15FixedMemoryPool10deallocateEPv>:
push   %rbp
mov    %rsp,%rbp
mov    %rdi,-0x8(%rbp)
mov    %rsi,-0x10(%rbp)
nop
pop    %rbp
ret
nop

0000000000100590 <_ZN9TailChainC1EPvj>:
push   %rbp
mov    %rsp,%rbp
mov    %rdi,-0x8(%rbp)
mov    %rsi,-0x10(%rbp)
mov    %edx,-0x14(%rbp)
mov    -0x8(%rbp),%rax
mov    -0x10(%rbp),%rdx
mov    %rdx,(%rax)
mov    -0x8(%rbp),%rax
mov    -0x14(%rbp),%edx
mov    %edx,0x8(%rax)
mov    -0x8(%rbp),%rax
movb   $0x0,0xc(%rax)
mov    -0x8(%rbp),%rax
movb   $0x0,0xd(%rax)
mov    -0x8(%rbp),%rax
movb   $0x0,0xe(%rax)
mov    -0x8(%rbp),%rax
movb   $0x0,0xf(%rax)
mov    -0x8(%rbp),%rax
movb   $0x0,0x10(%rax)
mov    -0x8(%rbp),%rax
movb   $0x0,0x11(%rax)
mov    -0x8(%rbp),%rax
movb   $0x0,0x12(%rax)
mov    -0x8(%rbp),%rax
movb   $0x0,0x13(%rax)
mov    -0x8(%rbp),%rax
movb   $0x0,0x14(%rax)
mov    -0x8(%rbp),%rax
movb   $0x0,0x15(%rax)
mov    -0x8(%rbp),%rax
movb   $0x0,0x16(%rax)
nop
pop    %rbp
ret
nop

0000000000100610 <_ZN9TailChainD1Ev>:
push   %rbp
mov    %rsp,%rbp
sub    $0x20,%rsp
mov    %rdi,-0x18(%rbp)
mov    -0x18(%rbp),%rax
mov    (%rax),%rax
mov    %rax,-0x8(%rbp)
jmp    100641 <_ZN9TailChainD1Ev+0x31>
mov    -0x8(%rbp),%rdx
mov    -0x18(%rbp),%rax
mov    %rdx,%rsi
mov    %rax,%rdi
call   10063c <_ZN9TailChainD1Ev+0x2c>
addq   $0x18,-0x8(%rbp)
mov    -0x18(%rbp),%rax
mov    (%rax),%rdx
mov    -0x18(%rbp),%rax
mov    0x8(%rax),%eax
mov    %eax,%ecx
mov    %rcx,%rax
add    %rax,%rax
add    %rcx,%rax
shl    $0x3,%rax
add    %rdx,%rax
cmp    %rax,-0x8(%rbp)
jb     100629 <_ZN9TailChainD1Ev+0x19>
mov    -0x18(%rbp),%rax
movl   $0x0,0x8(%rax)
mov    -0x18(%rbp),%rax
movb   $0x0,0xc(%rax)
mov    -0x18(%rbp),%rax
movb   $0x0,0xd(%rax)
mov    -0x18(%rbp),%rax
movb   $0x0,0xe(%rax)
mov    -0x18(%rbp),%rax
movb   $0x0,0xf(%rax)
mov    -0x18(%rbp),%rax
movb   $0x0,0x10(%rax)
mov    -0x18(%rbp),%rax
movb   $0x0,0x11(%rax)
nop
leave
ret
nop

00000000001006a6 <_ZN9TailChain23search_for_struct_spaceEv>:
push   %rbp
mov    %rsp,%rbp
mov    %rdi,-0x18(%rbp)
mov    -0x18(%rbp),%rax
mov    (%rax),%rax
mov    %rax,-0x8(%rbp)
jmp    1006d2 <_ZN9TailChain23search_for_struct_spaceEv+0x2c>
mov    -0x8(%rbp),%rax
movzbl 0x14(%rax),%eax
test   %al,%al
je     1006cd <_ZN9TailChain23search_for_struct_spaceEv+0x27>
mov    -0x8(%rbp),%rax
jmp    1006fd <_ZN9TailChain23search_for_struct_spaceEv+0x57>
addq   $0x18,-0x8(%rbp)
mov    -0x18(%rbp),%rax
mov    (%rax),%rdx
mov    -0x18(%rbp),%rax
mov    0x8(%rax),%eax
mov    %eax,%ecx
mov    %rcx,%rax
add    %rax,%rax
add    %rcx,%rax
shl    $0x3,%rax
add    %rdx,%rax
cmp    %rax,-0x8(%rbp)
jb     1006bb <_ZN9TailChain23search_for_struct_spaceEv+0x15>
mov    $0x0,%eax
pop    %rbp
ret
nop

0000000000100700 <_ZN9TailChain15handle_overflowEPFvPvES0_NS_12FuncPriorityE>:
push   %rbp
mov    %rsp,%rbp
sub    $0x20,%rsp
mov    %rdi,-0x8(%rbp)
mov    %rsi,-0x10(%rbp)
mov    %rdx,-0x18(%rbp)
mov    %ecx,-0x1c(%rbp)
cmpl   $0x1,-0x1c(%rbp)
je     100786 <_ZN9TailChain15handle_overflowEPFvPvES0_NS_12FuncPriorityE+0x86>
cmpl   $0x1,-0x1c(%rbp)
jg     100789 <_ZN9TailChain15handle_overflowEPFvPvES0_NS_12FuncPriorityE+0x89>
cmpl   $0xffffffff,-0x1c(%rbp)
je     10078c <_ZN9TailChain15handle_overflowEPFvPvES0_NS_12FuncPriorityE+0x8c>
cmpl   $0x0,-0x1c(%rbp)
je     100731 <_ZN9TailChain15handle_overflowEPFvPvES0_NS_12FuncPriorityE+0x31>
jmp    100789 <_ZN9TailChain15handle_overflowEPFvPvES0_NS_12FuncPriorityE+0x89>
mov    -0x8(%rbp),%rax
movzbl 0x12(%rax),%eax
test   %al,%al
je     100751 <_ZN9TailChain15handle_overflowEPFvPvES0_NS_12FuncPriorityE+0x51>
mov    -0x8(%rbp),%rax
movzbl 0x13(%rax),%eax
lea    0x1(%rax),%edx
mov    -0x8(%rbp),%rax
mov    %dl,0x13(%rax)
jmp    10078d <_ZN9TailChain15handle_overflowEPFvPvES0_NS_12FuncPriorityE+0x8d>
mov    -0x8(%rbp),%rax
movzbl 0x13(%rax),%eax
lea    0x1(%rax),%edx
mov    -0x8(%rbp),%rax
mov    %dl,0x13(%rax)
mov    -0x8(%rbp),%rax
movzbl 0x12(%rax),%eax
add    $0x1,%eax
mov    %eax,%edx
mov    -0x8(%rbp),%rax
mov    %dl,0x12(%rax)
mov    -0x10(%rbp),%rdx
mov    -0x18(%rbp),%rax
mov    %rax,%rdi
call   *%rdx
jmp    10078d <_ZN9TailChain15handle_overflowEPFvPvES0_NS_12FuncPriorityE+0x8d>
nop
jmp    10078d <_ZN9TailChain15handle_overflowEPFvPvES0_NS_12FuncPriorityE+0x8d>
nop
jmp    10078d <_ZN9TailChain15handle_overflowEPFvPvES0_NS_12FuncPriorityE+0x8d>
nop
nop
leave
ret

0000000000100790 <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE>:
push   %rbp
mov    %rsp,%rbp
sub    $0x30,%rsp
mov    %rdi,-0x18(%rbp)
mov    %rsi,-0x20(%rbp)
mov    %rdx,-0x28(%rbp)
mov    %ecx,-0x2c(%rbp)
mov    -0x18(%rbp),%rax
mov    %rax,%rdi
call   1007b3 <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0x23>
mov    %rax,-0x8(%rbp)
cmpq   $0x0,-0x8(%rbp)
jne    1007da <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0x4a>
mov    -0x2c(%rbp),%ecx
mov    -0x28(%rbp),%rdx
mov    -0x20(%rbp),%rsi
mov    -0x18(%rbp),%rax
mov    %rax,%rdi
call   1007d5 <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0x45>
jmp    1008b1 <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0x121>
mov    -0x8(%rbp),%rax
mov    -0x2c(%rbp),%edx
mov    %edx,0x10(%rax)
cmpl   $0x3,-0x2c(%rbp)
je     100863 <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0xd3>
cmpl   $0x3,-0x2c(%rbp)
jg     100877 <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0xe7>
cmpl   $0x2,-0x2c(%rbp)
je     10084f <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0xbf>
cmpl   $0x2,-0x2c(%rbp)
jg     100877 <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0xe7>
cmpl   $0x1,-0x2c(%rbp)
je     10083b <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0xab>
cmpl   $0x1,-0x2c(%rbp)
jg     100877 <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0xe7>
cmpl   $0xffffffff,-0x2c(%rbp)
je     10081a <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0x8a>
cmpl   $0x0,-0x2c(%rbp)
je     100827 <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0x97>
jmp    100877 <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0xe7>
mov    -0x18(%rbp),%rax
movb   $0x1,0xd(%rax)
jmp    1008b1 <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0x121>
mov    -0x18(%rbp),%rax
movzbl 0xe(%rax),%eax
lea    0x1(%rax),%edx
mov    -0x18(%rbp),%rax
mov    %dl,0xe(%rax)
jmp    100892 <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0x102>
mov    -0x18(%rbp),%rax
movzbl 0xf(%rax),%eax
lea    0x1(%rax),%edx
mov    -0x18(%rbp),%rax
mov    %dl,0xf(%rax)
jmp    100892 <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0x102>
mov    -0x18(%rbp),%rax
movzbl 0x10(%rax),%eax
lea    0x1(%rax),%edx
mov    -0x18(%rbp),%rax
mov    %dl,0x10(%rax)
jmp    100892 <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0x102>
mov    -0x18(%rbp),%rax
movzbl 0x11(%rax),%eax
lea    0x1(%rax),%edx
mov    -0x18(%rbp),%rax
mov    %dl,0x11(%rax)
jmp    100892 <_ZN9TailChain3regEPFvPvES0_NS_12FuncPriorityE+0x102>
mov    -0x18(%rbp),%rax
movzbl 0x11(%rax),%eax
lea    0x1(%rax),%edx
mov    -0x18(%rbp),%rax
mov    %dl,0x11(%rax)
mov    -0x18(%rbp),%rax
movb   $0x1,0xc(%rax)
nop
mov    -0x8(%rbp),%rax
mov    -0x20(%rbp),%rdx
mov    %rdx,(%rax)
mov    -0x8(%rbp),%rax
mov    -0x28(%rbp),%rdx
mov    %rdx,0x8(%rax)
mov    -0x8(%rbp),%rax
movb   $0x0,0x14(%rax)
leave
ret
nop

00000000001008b4 <_ZN9TailChain5cleanEPNS_18TailChain_FuncListE>:
push   %rbp
mov    %rsp,%rbp
mov    %rdi,-0x8(%rbp)
mov    %rsi,-0x10(%rbp)
mov    -0x10(%rbp),%rax
movq   $0x0,0x8(%rax)

mov    -0x10(%rbp),%rax
movq   $0x0,(%rax)
mov    -0x10(%rbp),%rax
movl   $0xffffffff,0x10(%rax)
mov    -0x10(%rbp),%rax
movb   $0x0,0x14(%rax)
nop
pop    %rbp
ret
nop
00000000001008ee <_ZN15FixedMemoryPool21Unable2Reg_error_tailEPNS_27Unable2Reg_error_tail_inputE>:
push   %rbp
mov    %rsp,%rbp
mov    %rdi,-0x8(%rbp)
nop
pop    %rbp
ret
nop

00000000001008fa <_ZN15FixedMemoryPool34Need2UpdateStatusList_warning_tailEPNS_40Need2UpdateStatusList_warning_tail_inputE>:
push   %rbp
mov    %rsp,%rbp
mov    %rdi,-0x8(%rbp)
mov    %rsi,-0x10(%rbp)
nop
pop    %rbp
ret

Disassembly of section .eh_frame:

0000000000000000 <.eh_frame>:
adc    $0x0,%al
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
add    %edi,0x52(%rdx)
add    %al,(%rcx)
js     1f <.eh_frame+0x1f>
add    %ebx,(%rbx)
or     $0x7,%al
or     %dl,0x18000001(%rax)
add    %al,(%rax)
add    %bl,(%rax,%rax,1)
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
(bad)
add    %al,(%rax)
add    %al,(%rax)
rex.B (bad)
adc    %al,0x60d4302(%rsi)
add    %al,(%rax)
add    %bl,(%rax,%rax,1)
add    %al,(%rax)
cmp    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
adc    (%rax),%eax
add    %al,(%rax)
add    %al,0xe(%rcx)
adc    %al,0x60d4302(%rsi)
rex.WRX or $0x7,%al
or     %al,(%rax)
add    %al,(%rax)
sbb    $0x0,%al
add    %al,(%rax)
pop    %rax
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
add    %bl,(%rdi)
add    %al,(%rax)
add    %al,(%rax)
rex.B (bad)
adc    %al,0x60d4302(%rsi)
pop    %rdx
or     $0x7,%al
or     %al,(%rax)
add    %al,(%rax)
and    %al,(%rax)
add    %al,(%rax)
js     7a <.eh_frame+0x7a>
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
and    %al,(%rax)
add    %al,(%rax)
add    %al,0xe(%rcx)
adc    %al,0x60d4302(%rsi)
pop    %rbx
or     $0x7,%al
or     %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
adc    $0x0,%al
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
add    %edi,0x52(%rdx)
add    %al,(%rcx)
js     b7 <.eh_frame+0xb7>
add    %ebx,(%rbx)
or     $0x7,%al
or     %dl,0x1c000001(%rax)
add    %al,(%rax)
add    %bl,(%rax,%rax,1)
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
(bad)
add    %eax,(%rax)
add    %al,(%rax)
rex.B (bad)
adc    %al,0x60d4302(%rsi)
add    (%rdx),%esp
add    %ecx,(%rdi,%rax,1)
or     %al,(%rax)
sbb    $0x0,%al
add    %al,(%rax)
cmp    $0x0,%al
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
(bad)
add    %al,(%rax)
add    %al,(%rax)
rex.B (bad)
adc    %al,0x60d4302(%rsi)
add    0xc(%rbx),%bl
(bad)
or     %al,(%rax)
add    %bl,(%rax,%rax,1)
add    %al,(%rax)
pop    %rsp
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
add    %dh,0x0(%rax)
add    %al,(%rax)
add    %al,0xe(%rcx)
adc    %al,0x60d4302(%rsi)
add    0xc(%rbx),%ch
(bad)
or     %al,(%rax)
add    %bl,(%rax,%rax,1)
add    %al,(%rax)
jl     116 <.eh_frame+0x116>
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
xchg   %eax,%esi
add    %al,(%rax)
add    %al,(%rax)
rex.B (bad)
adc    %al,0x60d4302(%rsi)
add    0x8070c(%rcx),%dl
add    %bl,(%rax,%rax,1)
add    %al,(%rax)
pushf
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
add    %dl,0x0(%rcx)
rex.B (bad)
adc    %al,0x60d4302(%rsi)
add    0x807(%rsp,%rcx,1),%cl
sbb    $0x0,%al
add    %al,(%rax)
mov    $0x0,%esp
add    %al,(%rax)
add    %dl,(%rax,%rax,1)
add    %al,(%rax)
add    %al,0xe(%rcx)
adc    %al,0x60d4302(%rsi)
rex.WRXB or $0x7,%al
or     %al,(%rax)
add    %al,(%rax)
sbb    $0x0,%al
add    %al,(%rax)
faddl  (%rax)
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
(bad)
add    %al,(%rax)
add    %al,(%rax)
rex.B (bad)
adc    %al,0x60d4302(%rsi)
rex.WB or $0x7,%al
or     %al,(%rax)
add    %al,(%rax)
sbb    $0x0,%al
add    %al,(%rax)
cld
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
add    %bl,0x0(%rsi)
rex.B (bad)
adc    %al,0x60d4302(%rsi)
add    0x8070c(%rcx),%bl
add    %bl,(%rax,%rax,1)
add    %al,(%rax)
sbb    $0x1,%al
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
je     1be <.eh_frame+0x1be>
add    %al,(%rax)
add    %al,0xe(%rcx)
adc    %al,0x60d4302(%rsi)
add    0xc(%rdi),%ch
(bad)
or     %al,(%rax)
add    %bl,(%rax,%rax,1)
add    %al,(%rax)
cmp    $0x1,%al
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
int3
add    %al,(%rax)
add    %al,(%rax)
rex.B (bad)
adc    %al,0x60d4302(%rsi)
add    %bh,%al
or     $0x7,%al
or     %al,(%rax)
add    %bl,(%rax,%rax,1)
add    %al,(%rax)
pop    %rsp
add    %eax,(%rax)
add    %al,(%rax)
add    %al,(%rax)
add    %cl,(%rdi)
add    %al,(%rax)
add    %al,(%rax)
rex.B (bad)
adc    %al,0x60d4302(%rsi)
rex.WX or $0x7,%al
or     %al,(%rax)
add    %al,(%rax)
sbb    $0x0,%al
add    %al,(%rax)
jl     217 <.eh_frame+0x217>
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
jg     21e <.eh_frame+0x21e>
add    %al,(%rax)
add    %al,0xe(%rcx)
adc    %al,0x60d4302(%rsi)
add    0xc(%rdx),%bh
(bad)
or     %al,(%rax)
add    %bl,(%rax,%rax,1)
add    %al,(%rax)
pushf
add    %eax,(%rax)
add    %al,(%rax)
add    %al,(%rax)
add    %dl,0x0(%rbp)
rex.B (bad)
adc    %al,0x60d4302(%rsi)
add    0x8070c(%rax),%dl
add    %bl,(%rax,%rax,1)
add    %al,(%rax)
mov    $0x1,%esp
add    %al,(%rax)
add    %bl,0x0(%rcx)
add    %al,(%rax)
add    %al,0xe(%rcx)
adc    %al,0x60d4302(%rsi)
add    0x7(%rsp,%rcx,1),%dl
or     %al,(%rax)
add    %bl,(%rax,%rax,1)
add    %al,(%rax)
faddl  (%rcx)
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
nop
add    %al,(%rax)
add    %al,(%rax)
rex.B (bad)
adc    %al,0x60d4302(%rsi)
add    0x8070c(%rbx),%cl
add    %bl,(%rax,%rax,1)
add    %al,(%rax)
cld
add    %eax,(%rax)
add    %al,(%rax)
add    %al,(%rax)
add    %ah,(%rbx)
add    %eax,(%rax)
add    %al,(%rax)
rex.B (bad)
adc    %al,0x60d4302(%rsi)
add    (%rsi),%ebx
add    %ecx,(%rdi,%rax,1)
or     %al,(%rax)
sbb    $0x0,%al
add    %al,(%rax)
sbb    $0x2,%al
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
cmp    %eax,(%rax)
add    %al,(%rax)
add    %al,0xe(%rcx)
adc    %al,0x60d4302(%rsi)
je     2d7 <.eh_frame+0x2d7>
(bad)
or     %al,(%rax)
add    %al,(%rax)
adc    $0x0,%al
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
add    %edi,0x52(%rdx)
add    %al,(%rcx)
js     2ef <.eh_frame+0x2ef>
add    %ebx,(%rbx)
or     $0x7,%al
or     %dl,0x1c000001(%rax)
add    %al,(%rax)
add    %bl,(%rax,%rax,1)
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
or     (%rax),%eax
add    %al,(%rax)
add    %al,0xe(%rcx)
adc    %al,0x60d4302(%rsi)
rex.RX or $0x7,%al
or     %al,(%rax)
add    %al,(%rax)
sbb    $0x0,%al
add    %al,(%rax)
cmp    $0x0,%al
add    %al,(%rax)
add    %al,(%rax)
add    %al,(%rax)
sldt   (%rax)
add    %al,(%rax)
rex.B (bad)
adc    %al,0x60d4302(%rsi)
rex.WX or $0x7,%al
or     %al,(%rax)
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
add    %al,0x43(%rdi)
rex.XB cmp (%r8),%spl
sub    %al,0x4e(%rdi)
push   %rbp
sub    %esp,(%rax)
xor    %esi,0x302e322e(%rip)        # 302e3240 <_ZN15FixedMemoryPool34Need2UpdateStatusList_warning_tailEPNS_40Need2UpdateStatusList_warning_tail_inputE+0x301e2946>
add    %al,(%rax)
rex.RXB
rex.XB
rex.XB cmp (%r8),%spl
sub    %al,0x4e(%rdi)
push   %rbp
sub    %esp,(%rax)
xor    %esi,0x302e322e(%rip)        # 302e3253 <_ZN15FixedMemoryPool34Need2UpdateStatusList_warning_tailEPNS_40Need2UpdateStatusList_warning_tail_inputE+0x301e2959>
add    %al,(%rax)
rex.RXB
rex.XB
rex.XB cmp (%r8),%spl
sub    %al,0x4e(%rdi)
push   %rbp
sub    %esp,(%rax)
xor    %esi,0x302e322e(%rip)        # 302e3266 <_ZN15FixedMemoryPool34Need2UpdateStatusList_warning_tailEPNS_40Need2UpdateStatusList_warning_tail_inputE+0x301e296c>
add    %al,(%rax)
rex.RXB
rex.XB
rex.XB cmp (%r8),%spl
sub    %al,0x4e(%rdi)
push   %rbp
sub    %esp,(%rax)
xor    %esi,0x302e322e(%rip)        # 302e3279 <_ZN15FixedMemoryPool34Need2UpdateStatusList_warning_tailEPNS_40Need2UpdateStatusList_warning_tail_inputE+0x301e297f>
	...
