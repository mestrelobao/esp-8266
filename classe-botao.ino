class Button {
    private:
        bool _state;
        uint8_t _pin;

    public:
        Button(uint8_t pin) : _pin(pin) {}

        void begin() {
            pinMode(_pin, INPUT_PULLUP);
            _state = digitalRead(_pin);
          }

        bool isReleased() {
            bool v = digitalRead(_pin);
            if (v != _state) {
                _state = v;
                if (_state) {
                    return true;
                }
            }
            return false;
        }
   
};
class Botao {
    private:
        bool _state;
        uint8_t _pin;

    public:
        Botao(uint8_t pin) : _pin(pin) {}

        void begin() {
            pinMode(_pin, INPUT_PULLUP);
            _state = digitalRead(_pin);
          }

        bool isReleased() {
            bool v = digitalRead(_pin);
            if (v != _state) {
                _state = v;
                if (!_state) {
                    return true;
                }
            }
            return false;
        }
   
};
Button myButton(0);
Botao meuBotao(0);

void setup() {
      myButton.begin();
      meuBotao.begin();
    Serial.begin(9600);
}

void loop() {
 
    if (meuBotao.isReleased()) {
        Serial.println(F("Pressed"));
    }
if (myButton.isReleased()) {
        Serial.println(F("Released"));
    }
     
    }
