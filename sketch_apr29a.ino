#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 



void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.begin(16, 2);
  loading("Cargando");

  Serial.begin(9600);
}

void loop() { 
  
}
void Open() {  
  while (true) {
    lcd.clear();
    
    // Texto de la primera línea
    String linea1 = "1. Usuarios   2. Introducir Un Codigo";
    
    // Texto de la segunda línea
    String linea2 = "Seleccionar";
    
    // Número seleccionado por el teclado
    char numeroSeleccionado = ' ';
    
    // Desplazar solo la primera línea
    for (int positionCounter = 0; positionCounter < 37; positionCounter++) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(linea1.substring(positionCounter));
      lcd.setCursor(0, 1);
      lcd.print(linea2 + ": " + numeroSeleccionado);
      delay(700);
    }

    // Resto del código...
    
    char key = keypad.getKey();

    if (key >= '0' && key <= '9') {
      numeroSeleccionado = key;
    }
    
    if (key == '1') {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Eligiendo Usuario...");
      // Codigo para iniciar sesion con usuario
    } else if (key == '2') {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Canjeando credito");
      // Codigo para canjear un codigo de credito
    }
    
    delay(100);
  }
}



void loading(char msg[]) {
  lcd.setCursor(0, 0);
  lcd.print(msg);

  for (int i = 0; i < 9; i++) {
    delay(1000);
    lcd.print(".");
  }

  Open(); // Continuar con la ejecución normal
}
