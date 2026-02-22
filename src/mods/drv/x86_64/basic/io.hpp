extern "C" {
    extern "C" void __attribute__((regparm(2))) outb(char data, unsigned short port);
    extern "C" void __attribute__((regparm(2))) outw(unsigned short data, unsigned short port);
    extern "C" void __attribute__((regparm(2))) outl(unsigned data, unsigned short port);
    extern "C" unsigned char __attribute__((regparm(1))) inb(unsigned short port);
    extern "C" unsigned short __attribute__((regparm(1))) inw(unsigned short port);
    extern "C" unsigned __attribute__((regparm(1))) inl(unsigned short port);
}