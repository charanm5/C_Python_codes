#include <stdio.h>
#include <stddef.h>

struct Packet {
    char c;
    int i;
    short s;
};

struct PacketOptimized {
    int i;
    short s;
    char c;
};

#pragma pack(1)
struct PackedPacket {
    char c;
    int i;
    short s;
};
#pragma pack()

int main() {
    struct Packet p;
    struct PacketOptimized po;
    struct PackedPacket pp;

    printf("Original struct size = %lu\n", sizeof(p));
    printf("Optimized struct size = %lu\n", sizeof(po));
    printf("Packed struct size = %lu\n\n", sizeof(pp));

    printf("Original offsets:\n");
    printf("c = %lu\n", offsetof(struct Packet, c));
    printf("i = %lu\n", offsetof(struct Packet, i));
    printf("s = %lu\n\n", offsetof(struct Packet, s));

    printf("Optimized offsets:\n");
    printf("i = %lu\n", offsetof(struct PacketOptimized, i));
    printf("s = %lu\n", offsetof(struct PacketOptimized, s));
    printf("c = %lu\n\n", offsetof(struct PacketOptimized, c));

    printf("Packed struct offsets:\n");
    printf("c = %lu\n", offsetof(struct PackedPacket, c));
    printf("i = %lu\n", offsetof(struct PackedPacket, i));
    printf("s = %lu\n\n", offsetof(struct PackedPacket, s));

    return 0;
}