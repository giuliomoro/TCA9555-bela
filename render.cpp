#include <Bela.h>
#include "TCA9555.h"

TCA9555 TCA(0x27);

void loop(void*)
{
	printf("Set pinMode16 INPUT\n");
	TCA.pinMode16(0xFFFF);
	printf("TEST read1(pin)");
	while(!Bela_stopRequested())
	{
		for (int pin = 0; pin < 16; pin++)
		{
			int val = TCA.read1(pin);
			printf("%d\t ", val);
		}
		printf("\n");
		usleep(100000);
	}
}

bool setup(BelaContext* context, void*)
{
	printf("TCA9555_LIB_VERSION: %s\n", TCA9555_LIB_VERSION);

	Wire.begin();
	TCA.begin();
	Bela_runAuxiliaryTask(loop);
	return true;
}

void render(BelaContext* context, void*)
{
}

void cleanup(BelaContext* context, void*)
{
}
