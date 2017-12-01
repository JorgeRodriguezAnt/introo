String morseLetras[] = {
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // a-i 
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // j-r 
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // s-z
};

int retardoPunto = 200;
int retardoRaya  = retardoPunto*3;
int retardoEspacio = retardoPunto*4;

int pinMorse = 8;
int pinEspacio = 7;

void setup() {
  pinMode(pinMorse, OUTPUT);
  pinMode(pinEspacio, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  //Completar código adecuadamente
  char ch;
  String ch_morse;
  
  int ch_valor;
  
  if (Serial.available()){
    ch = Serial.read();

    ch_valor = ch;
    
    Serial.print(ch);
    Serial.print(" ");
    if(ch_valor == 32){
      Serial.println("Espacio");
      parpadeoEspacio();
      //Agegar funcion
    }
    else{
      ch_morse = morseLetras[ch_valor - 97];
      Serial.println(ch_morse);
      String secuenciaMorse=ch_morse; 
      secuencia(secuenciaMorse); 
     
      //Agegar funcion
    }
  }
}


void secuencia(String secuenciaMorse){
  //Completar código adecuadamente
  //Llama en forma iterativa a la función
  //parpadeoPuntoRaya()
  
  int largo = secuenciaMorse.length();
  Serial.println(largo);
  for(int i=1; i<largo; i++){
    if(secuenciaMorse[i] == '.'){
      char puntoRaya='.';
      parpadeoPuntoRaya(puntoRaya);
    }
    else if(secuenciaMorse[i] == '-'){
      char puntoRaya='-';
      parpadeoPuntoRaya(puntoRaya);
    }
 }
}

void parpadeoPuntoRaya(char puntoRaya){
  if(puntoRaya == '.'){
    digitalWrite(8, HIGH); 
    delay(retardoPunto);
    digitalWrite(8, LOW);
  }
  else{
      digitalWrite(8,HIGH);
      delay(retardoRaya);
      digitalWrite(8, LOW);
  }
}

void parpadeoEspacio(){
      digitalWrite(7, HIGH);
      delay(retardoEspacio);
      digitalWrite(7, LOW);
     }
  //Completar código adecuadamente
