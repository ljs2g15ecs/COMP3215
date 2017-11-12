## Cross-compilation commands 
CC      	= arm-none-eabi-gcc
OBJCOPY 	= arm-none-eabi-objcopy

SRC 		= 
BUILD 		= Build
name		= Blinky
NAME		= $(BUILD)/$(name)
FLASH		= E:\

## Platform and optimization options
AFLAGS		= -mthumb -mcpu=cortex-m0plus
CFLAGS		= -Wall -ffreestanding $(AFLAGS) -DCPU_MKW41Z512VHT4
LFLAGS		= -T$(SRC)MKW41Z512xxx4_flash.ld $(AFLAGS) --specs=nosys.specs

src 		= $(wildcard $(SRC)board/*.c) \
			  $(wildcard $(SRC)CMSIS/*.c) \
			  $(wildcard $(SRC)drivers/*.c) \
			  $(wildcard $(SRC)freertos/*.c) \
			  $(wildcard $(SRC)source/*.c) \
			  $(wildcard $(SRC)utilities/*.c)
start		= $(SRC)startup/startup_MKW41Z4.S
			  

INC			= -I$(SRC)board \
			  -I$(SRC)CMSIS \
			  -I$(SRC)drivers \
			  -I$(SRC)freertos \
			  -I$(SRC)source \
			  -I$(SRC)utilities

obj			= $(src:.c=.o) $(start:.S=.o)
			
all:  $(BUILD) $(NAME).bin

$(BUILD):
	mkdir $@

$(NAME).bin: $(NAME).elf
	$(OBJCOPY) -O binary $< $@
	
$(NAME).elf: $(obj)
	$(CC) $(LFLAGS) -o $@ $^
	
%.o: %.c
	$(CC) -c $(CFLAGS) $(INC) $^ -o $@
	
%.o: %.S
	$(CC) -c $(CFLAGS) $(INC) $^ -o $@

.PHONY: flash
flash:
	copy /y $(BUILD)\$(name).bin $(FLASH)

.PHONY: clean
clean:
	del $(NAME).bin $(NAME).elf
