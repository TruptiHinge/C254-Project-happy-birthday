// define frequency notes
#define  C     2109.89
#define D 1879.69
#define E 1674.62
#define f 1580.63
#define G 1408.18
#define A 1760.18
#define B 1975.50

int speakerOut = 26;
int DEBUG = 1;
void setup() {
  pinMode(speakerOut, OUTPUT);
  if (DEBUG) {
    Serial.begin(9600); 
  }
}

double melody[] = {
  C,D,C,f,f,
  C,D,C,G,f,
  C,C,A,f,E,D,
  B,A,f,G,f 
};

int MAX_COUNT = sizeof(melody) / 2; 

long tempo = 10000;

int pause = 1000;

int rest_count = 2; 

int tone_ = 0;
int beat = 0;
long duration  = 0;

void playTone() {
long elapsed_time =0;
if (tone_>0){
  while(elapsed_time < duration){
      digitalWrite(speakerOut, HIGH);
      delay(tone_/2);
      digitalWrite(speakerOut, LOW);
      delay(tone_/2);

      elapsed_time +=(tone_);
  }
}

  else { 
    for (int j = 0; j < rest_count; j++) { 
      delayMicroseconds(duration); 
    } 
  }                                
}

void loop() {
for (int i = 0; i <MAX_COUNT; i++)
  {
    tone_ = melody[i];
    beat =50;

    duration = beat*tempo;

    playTone();


    delayMicroseconds(paaus); 
  }

 }
