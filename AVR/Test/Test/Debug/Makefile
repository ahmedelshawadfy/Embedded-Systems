################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../Test.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
Test.o

OBJS_AS_ARGS +=  \
Test.o

C_DEPS +=  \
Test.d

C_DEPS_AS_ARGS +=  \
Test.d

OUTPUT_FILE_PATH +=Test_6_2.elf

OUTPUT_FILE_PATH_AS_ARGS +=Test_6_2.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler



./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR32/GNU C Compiler : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE)  -x c -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.150\include"  -O1 -ffunction-sections -masm-addr-pseudos -g3 -Wall -mpart=mega328p -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR32/GNU Linker : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Test_6_2.map" -Wl,--start-group -lm  -Wl,--end-group -Wl,--gc-sections --rodata-writable -Wl,--direct-data -mpart=mega328p  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature "Test_6_2.elf" "Test_6_2.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Test_6_2.elf" "Test_6_2.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-objdump.exe" -h -S "Test_6_2.elf" > "Test_6_2.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Test_6_2.elf" "Test_6_2.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-size.exe" "Test_6_2.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Test_6_2.elf" "Test_6_2.a" "Test_6_2.hex" "Test_6_2.lss" "Test_6_2.eep" "Test_6_2.map" "Test_6_2.srec" "Test_6_2.usersignatures"
	