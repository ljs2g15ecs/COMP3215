## Cross-compilation commands 
CC      	= arm-none-eabi-gcc
OBJCOPY 	= arm-none-eabi-objcopy

SRC 		= Blinky
BUILD 		= GCC_Make
NAME		= $(BUILD)/Blinky

## Platform and optimization options
AFLAGS		= -mthumb -mcpu=cortex-m0plus
CFLAGS		= -Wall -ffreestanding $(AFLAGS) -DCPU_MKW41Z512VHT4
LFLAGS		= -T$(SRC)/MKW41Z512xxx4_flash.ld $(AFLAGS) --specs=nosys.specs

src 		= $(wildcard $(SRC)/board/*.c) \
			  $(wildcard $(SRC)/CMSIS/*.c) \
			  $(wildcard $(SRC)/drivers/*.c) \
			  $(wildcard $(SRC)/freertos/*.c) \
			  $(wildcard $(SRC)/source/*.c) \
			  $(wildcard $(SRC)/utilities/*.c)
start		= $(SRC)/startup/startup_MKW41Z4.S
			  

INC			= -IBlinky/board \
			  -IBlinky/CMSIS \
			  -IBlinky/drivers \
			  -IBlinky/freertos \
			  -IBlinky/source \
			  -IBlinky/utilities

obj			= $(src:.c=.o) $(start:.S=.o)
			
all: $(NAME).bin

$(NAME).bin: $(NAME).elf
	$(OBJCOPY) -O binary $< $@
	
$(NAME).elf: $(obj)
	$(CC) $(LFLAGS) -o $@ $^
	
%.o: %.c
	$(CC) -c $(CFLAGS) $(INC) $^ -o $@
	
%.o: %.S
	$(CC) -c $(CFLAGS) $(INC) $^ -o $@
	
$(BUILD):
	mkdir -p $@
	
.PHONY: clean
clean:
	del $(NAME).bin $(NAME).elf
