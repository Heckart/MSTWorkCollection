#include <avr/io.h>


void NeoPixel_Init(unsigned char NeoPixel_Array[30])
{
    unsigned char NP_Init_values[30] = {0x30, 0x00, 0x00, 0x30, 0x10, 0x00, 0x20, 0x20, 0x00, 0x10, 0x30, 0x00, 0x00, 0x30, 0x10, 0x00, 0x20, 0x20, 0x00, 0x10, 0x30, 0x00, 0x00, 0x30, 0x10, 0x00, 0x20, 0x20, 0x00, 0x10};
    
    DDRB = 0x01;
    
    for(unsigned char i = 0; i < 30; i++)
    {
        NeoPixel_Array[i] = NP_Init_values[i];
    }
    
    Update_Pixels(NeoPixel_Array);
    
    return;
}
void Blue_Flash(unsigned char NeoPixel_Array[30])
{

    for(unsigned char k = 0; k < 10; k++)
    {
    unsigned char BLUE_VALS[30] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    unsigned int Cur_Blue = k * 3;    
    
    BLUE_VALS[Cur_Blue+2] = 0x30;
    DDRB = 0x01;
    
    for(unsigned char i = 0; i < 30; i++)
    {
        NeoPixel_Array[i] = BLUE_VALS[i];
    }
    
    Update_Pixels(NeoPixel_Array);
    Delay(30);
    }
    return;
}
void Sequence_1(unsigned char NeoPixel_Array[30])
{
    for(unsigned char k =1; k < 10; k++)
    {
        
    unsigned char NP_Init_values[30] = {0x30, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x30};
    
    DDRB = 0x01;
    
    for(unsigned char i = 0; i < 30; i++)
    {
        NeoPixel_Array[i] = NP_Init_values[i];
    }
    
    
    Update_Pixels(NeoPixel_Array);
    Delay(3);
        
    unsigned char NP_Init_values2[30] = {0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00};
    
    DDRB = 0x01;
    
    for(unsigned char i = 0; i < 30; i++)
    {
        NeoPixel_Array[i] = NP_Init_values2[i];
    }
    Update_Pixels(NeoPixel_Array);    
    
    Delay(3);
    }
    
    return;
}

void Sequence_2(unsigned char NeoPixel_Array[30])
{
        unsigned char NP_Init_values[30] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
        
        DDRB = 0x01;
        
        for(unsigned char k =1; k < 20; k++)
        {        
        
            for(unsigned char i = 0; i < 30; i++)
            {
                NeoPixel_Array[i] += 1 ;
            }
        
            Update_Pixels(NeoPixel_Array);
            Delay(3);
        }
        
        for(unsigned char k =1; k < 20; k++)
        {
            
            for(unsigned char i = 0; i < 30; i++)
            {
                NeoPixel_Array[i] -= 1 ;
            }
            
            Update_Pixels(NeoPixel_Array);
            Delay(3);
        }        
        
    
    return;
}

void Sequence_3(unsigned char NeoPixel_Array[30])
{
    unsigned char NP_Init_values[30] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    
    DDRB = 0x01;
    
    for(unsigned char k =1; k < 20; k++)
    {
        
        for(unsigned char i = 0; i < 30; i++)
        {
            int r = rand();
            r % 31;
            NeoPixel_Array[i] = r ;
        }
        
        Update_Pixels(NeoPixel_Array);
        Delay(5);
    }
    return;
}

void Update_Pixels(unsigned char NeoPixel_Array[30])
{
    for(unsigned int i = 0; i < 30; i+= 3)
    {
        Send_Pixel(NeoPixel_Array[i], NeoPixel_Array[i + 1], NeoPixel_Array[i + 2]);
    }

    return;
}

void Send_Pixel(unsigned char red, unsigned char green, unsigned char blue){
    Send_Byte(green);
    Send_Byte(red);
    Send_Byte(blue);
    return;
}

void Send_Byte(unsigned char val)
{
    
    for(unsigned char i = 0; i < 8; i++)
    {
        
        PORTB = 0x01;
        if(val &0x80)
        {
            PORTB = 0x01;
            PORTB = 0x01;
            }else{
            PORTB = 0x00;
            PORTB = 0x00;
        }
        PORTB = 0x00;
        val = val << 1;
    }

    return;
}
void Clear_Pixels(unsigned char NeoPixel_Array[30])
{
    for(unsigned char a = 0; a<30; a++){
        NeoPixel_Array[a] = 0;
    }
    return;
}

void CheckButton(unsigned char NeoPixel_Array[30])
{
            if (PIND & 0x10)
            {
                Sequence_1(NeoPixel_Array);

                //turn all neopixels off
                Clear_Pixels(NeoPixel_Array);
                Update_Pixels(NeoPixel_Array);
                
                Sequence_2(NeoPixel_Array);

                //turn all neopixels off
                Clear_Pixels(NeoPixel_Array);
                Update_Pixels(NeoPixel_Array);
                
                Sequence_3(NeoPixel_Array);

                //turn all neopixels off
                Clear_Pixels(NeoPixel_Array);
                Update_Pixels(NeoPixel_Array);

                beep(349); // F
                    beep(349); // F
                   beep(349); // F
                    beep(262); // C
                    beep(294); // D
                    beep(294); // D
                    beep(262); // C
                    DelayMS(20); // rest

                    beep(440); // A
                    beep(440); // A
                    beep(392); // G
                    beep(392); // G
                    beep(349); // F
                    DelayMS(20); // rest

                    beep(262); // C
                    beep(349); // F
                    beep(349); // F
                    beep(349); // F
                    beep(262); // C
                    beep(294); // D
                    beep(294); // D
                    beep(262); // C
                    DelayMS(20); // rest
    
                    beep(440); // A
                    beep(440); // A
                    beep(392); // G
                    beep(392); // G
                    beep(349); // F
                    DelayMS(20); // rest
            }
}

void Delay(unsigned char delay_val)
{
    unsigned int real_delay = delay_val * 191;
    unsigned int delay_back = 0xFFFF - real_delay + 1;
    TCNT1H = delay_back/0x100;
    TCNT1L = delay_back % 0x100;
    TCCR1A = 0x00; //Normal mode
    TCCR1B = 0x05; //Normal mode, 1:1024 pre-scalar
    
    while ((TIFR1 &(0x1<<TOV1))==0);
    
    TCCR1B = 0;
    TIFR1 = 0x1<<TOV1;
    return;
}

unsigned char ReadLight()
{ 
    ADMUX = ADMUX & 0xE0;
    ADCSRA = ADCSRA | 0x50;
    while (ADCSRA & (1<<4))
    {};
    return ADCH;
}

//This function will create a delay for a passed in amount of Milliseconds 
void DelayMS(int length) 
{ 
length = length * 10; 
length = length - 1; //255 
if(length > 255) { OCR1AH = length & 0xFF00; } 
OCR1AL = length & 0x00FF; //Load lower byte of 15624 into output compare register 
TCCR1A = 0b00000000; 
TCCR1B = 0b00001101; //Turn on CTC mode and prescaler of CLK/1024
while((TIFR1 & (1<<OCF1A)) == 0); //If OCF1A is set (TCNT1 = OCR1A), break 
TIFR1 = (1<<OCF1A);
}

//This toggles the Speaker on port C with a frequency of 220HZ which is a period of 4546 us. 
void beep(unsigned int hz) {
int length = 50; 
for(double i = 0; i < length; i++) {
PORTC = 0b01000000; //turns speaker on 
DelayMS(hz); 
PORTC = 0b00000000;//turns speaker off 
DelayMS(284); } 
DelayMS(50); }



int main()
{

    ADCSRA = 0x96;
    ADMUX = 0xE0;
    DIDR0 =0x81;
    PORTD &= 0b11101111;
    DDRC |= 0B11000000;

DDRB = 0xFF; // Initialize Port B for Output 
PORTB = 0x01; //output to portB bit 1 
PINB |= 0b00000001;

    // neopixel array of colors
    unsigned char NeoPixel_Array[30]  = {0x30, 0x00, 0x00, 0x30, 0x10, 0x00, 0x20, 0x20, 0x00, 0x10, 0x30, 0x00,
    0x00, 0x30, 0x10, 0x00, 0x20, 0x20, 0x00, 0x10, 0x30, 0x00, 0x00, 0x30, 0x10, 0x00, 0x20, 0x20, 0x00, 0x10};
    
    //initialize neopixels (makes all neopixels light up)
    NeoPixel_Init(NeoPixel_Array);    
    //delay 0.5s 
    Delay(50);
    
    //turn all neopixels off
    Clear_Pixels(NeoPixel_Array);
    Update_Pixels(NeoPixel_Array);    
    
    //Flash each neopixel in order
    Blue_Flash(NeoPixel_Array);

    //turn all neopixels off
    Clear_Pixels(NeoPixel_Array);
    Update_Pixels(NeoPixel_Array);
    
    PORTD &= 0b11101111;

    while (1)
    {
        unsigned char light_val = ReadLight();  
        light_val = ReadLight() & 0x3F; 
        Delay(2);
        if(light_val >= 1)
        {
            PORTC |= 0B10000000;
            CheckButton(NeoPixel_Array);
        }
        else        
        {
            PORTC &= 0B01111111;
            CheckButton(NeoPixel_Array);
        }
        
    }
}