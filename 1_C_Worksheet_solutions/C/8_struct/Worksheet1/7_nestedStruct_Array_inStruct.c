#include <stdio.h>

typedef struct {
    int id;
    float value;
} Sensor;

typedef struct {
    int header;
    Sensor sensor;
    unsigned char payload[5];
} Packet;

typedef struct {
    Sensor sensors[3];
} SensorArray;

int main() {
    SensorArray sa;

    sa.sensors[0].id = 1;
    sa.sensors[0].value = 10.5;

    sa.sensors[1].id = 2;
    sa.sensors[1].value = 20.5;

    sa.sensors[2].id = 3;
    sa.sensors[2].value = 30.5;

    printf("Sensor Array:\n");
    for (int i = 0; i < 3; i++) {
        printf("ID=%d Value=%.2f\n",
               sa.sensors[i].id,
               sa.sensors[i].value);
    }

    Packet p;

    p.header = 0xAA;
    p.sensor.id = 99;
    p.sensor.value = 55.5;

    for (int i = 0; i < 5; i++) {
        p.payload[i] = i + 1;
    }

    printf("\nPacket Data:\n");
    printf("Header = 0xX\n");
    printf("Sensor ID = %d\n", p.sensor.id);
    printf("Sensor Value = %.2f\n", p.sensor.value);

    printf("Payload: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", p.payload[i]);
    }
    printf("\n");

    return 0;
}