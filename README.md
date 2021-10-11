# arduino_project1
Kontrola servo uređaja koristeći Arduino razvojni sistem

1. Uvod
2. 
Sama ideja projekta jeste izvršiti kontrolu servo motora koristeći džojstik. Kao posredni uređaj koji će nam sve ovo obezbediti, koristićemo Arduino razvojni sistem koji je open-source code tipa. Projekat se izrađuje u svrhu predmeta pod imenom Samostalni praktični projekat.
Motivacija je osmisliti kompatibilan sistem upravljanja koji se može ukombinovati u bilo koju svrhu, primera: sistem se može ugraditi u robota koji je bežično kontrolisan, i biti korišćen za pristup nepreglednim, nepristupačnim ili pak opasnim mestima po čoveka. Na servo motore se može ugraditi, laser, kamera ili otale komponente u zavisnosti od svrhe u koje će se koristiti.

U daljim odeljcima dokumenta ćete se susreti sa analizom zadatka gde možete pročitati nešto više o samoj sistematici uređaja, kako ćemo ukombinovati dva servo motora.
Nakon toga sledi opis svih hardverskih komponenti koje se koriste za izradu ovog projekta.
Kada se upoznamo sa samim komponentama prelazimo na kod koji će se izvršavati na razvojnom sistemu i koji će nam zaokružiti celu priču kako šta funkcioniše.
Na kraju svega završavamo tesiranjem funkcionalnosti uređaja u celosti, zaokružujemo rezultat i izvodimo generalni zaključak.

2. Analiza zadatka
3. 
Princip koji se koristi za ovakve tipove uređajaj je jednostavna robotizovana ruka. Može se ostvariti jednostavnim električnim servo motorima, hidrauličnim komponentama ukoliko je u pitanju rad sa težim stvarima. Jedan servo motor pokriva jednu osu po kojoj će se robotizovana ruka kretati, u našem primeru to su dva servo motora od kojih će jedan vršiti pomeranje po x osi, a drugi po y osi. U industriji proizvodnje uglavnom ćemo se susretati sa robotima koji imaju 3 ose.

3. Opis hardverskih delova


Komponente koje koristimo za izradu su sledeće:

-Arduino Uno R3
-Arduino džojstik KY-023
-Servo motor SG90 2x
-Laser modul KY-008
-Breadboard 400
Aruino Uno R3 specifikacija: (detaljna slika razvojnog sistema je u dodatku na kraju dokumenta)
Mikrokontroler:	ATmega328
Radni napon:	5V
Napon napajanja (preporučeno):	7-12V
Maksimalni napon napajanja (ne preporučuje se):	20V
Digitalni I/O pinovi:	14 (od kojih 6 obezbedjuje PWM izlaz)
Analogni ulazni pinovi	: 6
DC (jednosmerna) struja po I/O pinu:	40mA
DC (jednosmerna) struja za pin na 3.3V:	50mA
Flash memorija:	32KB (ATmega328) od kojih je 0.5 KB iskorišćeno za bootloader
SRAM:	2KB (ATmega328)
EEPROM:	1KB (ATmega328)
Clock Speed:	16MHz

Arduino joystick KY-023 specifikacije:

Radna brzina: 0,12s / 60° (4,8V), 0,10s / 60° (6.0V)
Temperatura: -30 ~ 60C°
Radni napon: 3.5 ~ 6V
Dimenzije: 32 x 3 x 12 mm
Težina: 9g
Servo motor SG90 specifikacije:
Kontrola: analogna (najbolje koristiti Servo library)
Napon: 5V
Brzina: 60 stupnjeva za 0.1s
Težina: 9g
Dimenzije: 23mm x 12mm x 29 mm

Laser modul KY-008 specifikacije:

Radna voltaza: 5V
Dimenzije: 15 * 24 mm
Tezina: 2.2 g

Sve komponente kombinujemo u po šematiku koji je naveden u dodatku dokumenta.
Dakle, po šematiku možemo videti da su ulazi i izlazi povezani ovako:
Servo motor: 

PWM(Orange) -> Arduino Digital I/0   (X na pin 9); (Y na pin 8)
VCC(Red) -> Arduino 5V Power Pin
Ground(Brown) -> Arduino Ground Pin

Džojstik: 

GND -> Arduino Ground pin
VCC -> Arduino 5V Power pin
X -> Arduino Analog A0 pin
Y -> Arduino Analog A1 pin
SW/Key -> Arduino Digital pin 7
Laser modul:
VCC(S) -> Arduino 5V Power pin
Ground(-) -> Arduino Ground pin

5. Rezultati testiranja


Razvojni sistem povezujemo sa računarom i sa njega preko programa za upravljanje sistemom spuštamo prethodno navedeni kod u memoriju razvojnog sistema i na njemu izvršavamo isti.
Dakle po kodu i objašnjenju pomeranje pečurkice džojstika levo i desno će aktivirati servo motor koji je zadužen za X osu i po njoj će rotirati komponente koje su na njega nakačene.
Isti princip je i za Y osu, pomeranjem pečurkice džojstika gore i dole će aktivirati drugi servo motor koji će rotirati nakačene komponente po Y osi.
Laser se po kodu automatski uključuje čim se sam kod krene izvršavati. IF naredba u kodu nam omogućuje da nakon pritiska dugmeta na džojstiku odnosno same pečurkice, isključimo laser.

6. Zaključak


Dakle, nakon što smo izvršili testiranje, razvojni sistem zajedno sa ostalim komponentama i dobro izrađenim kodom nam omogućava upravljanje servo motorima koristeći džojstik. Takođe koristimo i laser kako bismo videli tačnije položaje servo motora u prostoru. Umesto lasera, može biti montirana i kamera, ultrazvučni senzor ili slično u zavisnosti od primene.
Pravac unapređenja ovog sistema bi bila montaža na robota koji koristi i step motore za kretanje, kao i bežični prijemnik/predajnik preko kog ćemo komunicirati sa sistemom i vršiti njegovo upravljanje na daljinu.

7. Literatura


Arduino sajt: Tutorial Arduino Mini Laser Turret Control, 06.09.2021. LINK
Arduino Modules: KY-023 / KY-008 / SG90 Servo 06.09.2021. LINK
