#define SYS_CTRL_RCC             (*((volatile unsigned long*)0x400FE060))
#define SYS_CTRL_RCGC0     (*((volatile unsigned long*)0x400FE100))
#define SYS_CTRL_RCGC2     (*((volatile unsigned long*)0x400FE108))
#define SYS_CTRL_RCGCADC    (*((volatile unsigned long*)0x400FE638))
#define SYS_CTRL_PRGPIO     (*((volatile unsigned long*)0x400FEA08))
#define SYS_CTRL_RCGCGPIO    (*((volatile unsigned long*)0x400FE608))
#define SYS_CTRL_GPIOHBCTL    (*((volatile unsigned long*)0x400FE06C))


//************************************************************************************************
//-------------------------GPIO PORTF REGISTERS---------------------------------------------------
//************************************************************************************************
#define GPIO_PORTF_DATA    (*((volatile unsigned long*)0x400253FC))
#define GPIO_PORTF_DIR    (*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN    (*((volatile unsigned long*)0x4002551C))
#define GPIO_PORTF_AFSEL   (*((volatile unsigned long*)0x40025420))

//************************************************************************************************
//-------------------------GPIO PORTE REGISTERS---------------------------------------------------
//************************************************************************************************
#define GPIO_PORTE_DATA   (*((volatile unsigned long*)0x400243FC))
#define GPIO_PORTE_DIR   (*((volatile unsigned long*)0x40024400))
#define GPIO_PORTE_DEN   (*((volatile unsigned long*)0x4002451C))
#define GPIO_PORTE_AFSEL   (*((volatile unsigned long*)0x40024420))
#define GPIO_PORTE_AMSEL   (*((volatile unsigned long*)0x40024528))

//*************************************************************************************************
//------------------------ADC REGISTER-------------------------------------------------------------
//*************************************************************************************************
#define ADC_ACTSS_R             (*((volatile unsigned long *)0x40038000))
#define ADC0_RIS_R              (*((volatile unsigned long *)0x40038004))
#define ADC0_IM_R               (*((volatile unsigned long *)0x40038008))
#define ADC0_ISC_R              (*((volatile unsigned long *)0x4003800C))
#define ADC0_EMUX_R             (*((volatile unsigned long *)0x40038014))
#define ADC0_SSPRI_R            (*((volatile unsigned long *)0x40038020))
#define ADC0_PSSI_R             (*((volatile unsigned long *)0x40038028))
#define ADC0_SSMUX3_R           (*((volatile unsigned long *)0x400380A0))
#define ADC0_SSCTL3_R           (*((volatile unsigned long *)0x400380A4))
#define ADC0_SSFIFO3_R          (*((volatile unsigned long *)0x40038048))
#define ADC_ACTSS_ASEN3         0x00000008  // ADC SS3 Enable
#define ADC_RIS_INR3            0x00000008  // SS3 Raw Interrupt Status
#define ADC_IM_MASK3            0x00000008  // SS3 Interrupt Mask
#define ADC_ISC_IN3             0x00000008  // SS3 Interrupt Status and Clear
#define ADC_EMUX_EM3_M          0x0000F000  // SS3 Trigger Select mask
#define ADC_EMUX_EM3_TIMER      0x00005000  // Timer
#define ADC_SSPRI_SS3_4TH       0x00003000  // fourth priority
#define ADC_SSPRI_SS2_3RD       0x00000200  // third priority
#define ADC_SSPRI_SS1_2ND       0x00000010  // second priority
#define ADC_SSPRI_SS0_1ST       0x00000000  // first priority
#define ADC_PSSI_SS3            0x00000008  // SS3 Initiate
#define ADC_SSMUX3_MUX0_M       0x00000003  // 1st Sample Input Select mask
#define ADC_SSMUX3_MUX0_S       0           // 1st Sample Input Select lshift
#define ADC_SSCTL3_TS0          0x00000008  // 1st Sample Temp Sensor Select
#define ADC_SSCTL3_IE0          0x00000004  // 1st Sample Interrupt Enable
#define ADC_SSCTL3_END0         0x00000002  // 1st Sample is End of Sequence
#define ADC_SSCTL3_D0           0x00000001  // 1st Sample Diff Input Select
#define ADC_SSFIFO3_DATA_M      0x000003FF  // Conversion Result Data mask
//*************************************************************************************************

#define NVIC_EN0_INT19          0x00080000  // Interrupt 19 enable
#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))  // IRQ 0 to 31 Set Enable Register
#define NVIC_PRI4_R             (*((volatile unsigned long *)0xE000E410))  // IRQ 16 to 19 Priority Register
#define TIMER0_CFG_R            (*((volatile unsigned long *)0x40030000))
#define TIMER0_TAMR_R           (*((volatile unsigned long *)0x40030004))
#define TIMER0_CTL_R            (*((volatile unsigned long *)0x4003000C))
#define TIMER0_IMR_R            (*((volatile unsigned long *)0x40030018))
#define TIMER0_MIS_R            (*((volatile unsigned long *)0x40030020))
#define TIMER0_RIS_R            (*((volatile unsigned long *)0x4003001C))
#define TIMER0_ICR_R            (*((volatile unsigned long *)0x40030024))
#define TIMER0_TAILR_R          (*((volatile unsigned long *)0x40030028))
#define TIMER0_TAPR_R           (*((volatile unsigned long *)0x40030038))
#define TIMER0_TAR_R            (*((volatile unsigned long *)0x40030048))
#define TIMER_CFG_16_BIT        0x00000004  // 16-bit timer configuration,
                                            // function is controlled by bits
                                            // 1:0 of GPTMTAMR and GPTMTBMR
#define TIMER_TAMR_TAMR_PERIOD  0x00000002  // Periodic Timer mode
#define TIMER_CTL_TAEN          0x00000001  // GPTM TimerA Enable
#define TIMER_IMR_TATOIM        0x00000001  // GPTM TimerA Time-Out Interrupt
                                            // Mask
#define TIMER_ICR_TATOCINT      0x00000001  // GPTM TimerA Time-Out Raw
                                            // Interrupt
#define TIMER_TAILR_TAILRL_M    0x0000FFFF  // GPTM TimerA Interval Load
                                            // Register Low
#define SYSCTL_RCGC1_R          (*((volatile unsigned long *)0x400FE104))
#define SYSCTL_RCGC1_TIMER0     0x00010000  // timer 0 Clock Gating Control
#define SYS_CTRL_RCGC2_GPIOF 0x00000020



//****************************************************************************************************
//--------------RUN MODE CLOCK CONFIGURATION REGISTER (RCC) BITS DEFINITION---------------------------
//****************************************************************************************************
#define   ACG      0x08000000;//Automatic Clock Gating Bit,
#define   SYS_DIV 0x07800000;//Clock Divisor
#define   USESYSDIV    0x00400000;//System Clock Divider
#define   USEPWMDIV    0x00100000;//Divsion of clock on PWM clock source.
#define   PWMDIV     0x000E0000;//PWM Frequency Division.
#define   PWRDN     0x00002000;//Clock in POWER DOWN .
#define   BYPASS     0x00000800;//PLL BYPASS bit.
#define   XTAL     0x000007C0;//Crystal Oscillator value.
#define   OSCSRC     0x00000030;//Oscillator Source Bit.
#define   MOSCDIS     0x00000001;//Main Oscillator Disable Bit.

#define   ADC_MODE0    0x00000001;
#define   ADC_MODE1    0x00000002;
//##################################################################################################
//**************************************************************************************************
//----------------------------FUNCTION PROTOTYPES---------------------------------------------------
//**************************************************************************************************

void EnableInterrupts(void);  // Enable interrupts
void Sys_Init(void);
void Perform_ADC(void);
void ADC_Init(void);
void Set_System_Frequency(void);
//**************************************************************************************************
unsigned int ISR_FLAG; //Flag to verify that whether control execute ISR or not.
volatile unsigned int ADC_ISR_FLAG;
unsigned int ADC_ISR_FLAG2;
unsigned long i=0;
//**************************************************************************************************
signed long ADC_DATA;


void main(void)
{
 Sys_Init();// Initialize GPIOF
 ADC_Init();//Initialization and Configuration of ADC
 while(1)
 {
  if(ADC_DATA>=360)
  {
   GPIO_PORTF_DATA=0x00000002;
  }
  else
  {
   GPIO_PORTF_DATA = 0x00000004;

  }
 }
}










void Sys_Init(void)
{
 SYS_CTRL_PRGPIO|=(SYS_CTRL_RCGC2_GPIOF);
 SYS_CTRL_RCGC2|=(SYS_CTRL_RCGC2_GPIOF);
 GPIO_PORTF_AFSEL&=~(1<<2);//Disable Alternate Function on PF2
 GPIO_PORTF_DIR=0x0000000F;//Make Output
 GPIO_PORTF_DEN=0x000000FF;// Digital Data is Enabled
 GPIO_PORTF_DATA=0x00000002;// Turn ON RED LED
}
void EnableInterrupts(void)
{
 __asm  ("    CPSIE  I\n"
    "    BX     LR\n");
}


void ADC_Init(void)
{
 ADC_ISR_FLAG=0;
 SYS_CTRL_RCGC0|=0x00010000;//Clock to ADC0
 SYS_CTRL_RCGCADC|=ADC_MODE0;//0x00000001 for Mode 0
 SYS_CTRL_RCGC2|=0x00000010;// CLOCK to PORTE
 GPIO_PORTE_DIR|=0xFFFFFFF8;//PE3 is Input
 GPIO_PORTE_AFSEL|=0x00000008;//Enable Alternate Function on PE3
 GPIO_PORTE_DEN&=~(0x00000008);//Clear Digital Data,for Analogue Input
 GPIO_PORTE_AMSEL|=0x0000000F;//Make pins enable for Analoue input
 ADC_ACTSS_R&=~(0x00000008);//Clear ADC Sample Sequencer3 which takes only 1 sample
 ADC0_EMUX_R|=0x0000F000;//SS3 Trigger Continuously Sample
 ADC0_SSMUX3_R|=0x00000002;//MUX3 all bits Enabled
 ADC0_SSCTL3_R|=0x0000000E;// Interrupt,1st sample is last
 ADC0_IM_R|=0x00000008;//Interrupt Mask 3
 ADC_ACTSS_R|=0x00000008;//Enable ADC Sample Sequencer3
 NVIC_EN0_R|=0x00020000;//Interrupt number is 17 for ADC SEQUENCE 3
 EnableInterrupts();
 }





void ADC0_Handler(void){
 ADC_ISR_FLAG=1;
 ADC_ISR_FLAG2=ADC_ISR_FLAG2+1;
  ADC0_ISC_R |= 0x0000000F;             // acknowledge ADC sequence 3 completion
  ADC_DATA = ADC0_SSFIFO3_R&ADC_SSFIFO3_DATA_M;
}
