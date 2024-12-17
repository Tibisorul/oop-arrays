# Aplicatii pe Arrays folosind conceptele Programarii Orientate pe Obiecte

## Descriere proiect

Proiectul este o aplicație C++ care permite gestionarea și manipularea unui set de array-uri. Utilizatorul poate crea, vizualiza, modifica și șterge array-uri, precum și aplica diverse operații asupra acestora, cum ar fi calculul minimului, maximului, poziției acestora, suma elementelor și sortarea array-ului. De asemenea, proiectul permite afișarea statisticilor (media, mediana, varianța) și identificarea dinamică a operațiilor utilizând dynamic_cast.

Proiectul utilizează concepte de Programare Orientată pe Obiecte (OOP), precum moștenirea, polimorfismul, excepțiile personalizate și dynamic_cast. Se folosește și STL (Standard Template Library) pentru funcționalități precum vectori, sortare și acumulare.

În cadrul **Milestone 3**, proiectul a fost extins cu:
- **Implementarea a două design patterns**: Singleton și Factory Method.
- **Utilizarea claselor și funcțiilor șablon (template)** pentru operații generice asupra array-urilor.
- **Logger** pentru înregistrarea evenimentelor în fișierul `log.txt`.

## 📂 Fișiere principale

- **`main.cpp`**: Punctul de intrare în aplicație, unde este inițializat meniul principal.
- **`ArrayMenu.h` / `ArrayMenu.cpp`**: Meniul principal pentru gestionarea array-urilor. Utilizatorul poate adăuga, șterge, vizualiza și opera asupra array-urilor.
- **`Array.h` / `Array.cpp`**: Clasa `Array`, care conține vectorul de elemente și metodele pentru manipularea acestuia.
- **`Element.h` / `Element.cpp`**: Clasa `Element`, care definește un element din array.
- **`CustomExceptions.h`**: Definirea excepțiilor personalizate, cum ar fi `InvalidSizeException`, `InvalidIndexException` și `EmptyArrayException`.
- **`Operation.h`**: Clasa de bază `Operation`, care definește o operație generică.
- **`SortOperation.h`**: Operație de sortare, derivată din `Operation`.
- **`StatisticsOperation.h`**: Operație de calcul al statisticilor array-ului (media, varianță, mediană).
- **`Logger.h` / `Logger.cpp`**: Implementarea design pattern-ului **Singleton** pentru un logger care înregistrează evenimentele într-un fișier `log.txt`.
- **`ArrayFactory.h` / `ArrayFactory.cpp`**: Implementarea design pattern-ului **Factory Method** pentru crearea obiectelor `Array` cu valori implicite sau date personalizate.
- **`Calculator.h`**: Clasă șablon (template) utilizată pentru operații generice asupra array-urilor (sumă, maxim, minim).

---

## 🛠️ Funcționalități principale

1. **Adăugarea, ștergerea și vizualizarea array-urilor**.
2. **Operații asupra array-urilor**:
   - Calculul minimului și maximului.
   - Determinarea poziției minimului și maximului.
   - Calculul sumei elementelor.
   - Sortarea elementelor (crescător/descrescător).
3. **Afișarea statisticilor**:
   - Media, varianța și mediana array-ului.
4. **Logger**:
   - Evenimentele sunt înregistrate într-un fișier `log.txt`.
5. **Template-uri (Clase și Funcții)**:
   - Clasa `Calculator` permite efectuarea operațiilor de sumă, maxim și minim pentru orice tip de date.
   - Funcția `afiseazaVector` permite înregistrarea vectorului în log.

---

## 🚀 Design Patterns implementate

1. **Singleton**:
   - Utilizat pentru implementarea clasei `Logger`, astfel încât să existe o singură instanță pentru înregistrarea evenimentelor.
2. **Factory Method**:
   - Implementat în clasa `ArrayFactory` pentru a crea obiecte de tip `Array` cu valori implicite sau date introduse.

---

## 🧩 Template-uri

- **Clasa `Calculator`**: Permite calcularea unor operații generice (sumă, maxim, minim) asupra unui vector de orice tip de date.
- **Funcția `afiseazaVector`**: O funcție șablon care scrie conținutul unui vector în log, fără a-l afișa în terminal.

---




## Milestone #0

- [ ] Nume proiect (poate fi schimbat ulterior)
- [ ] Scurtă descriere a temei alese, ce v-ați propus să implementați

## Milestone #1

#### Cerințe
- [ ] definirea a minim **3-4 clase** folosind compunere cu clasele definite de voi
- [ ] constructori de inițializare cu parametri
- [ ] pentru o aceeași (singură) clasă: constructor de copiere, `operator=` de copiere, destructor
- [ ] `operator<<` pentru toate clasele pentru afișare (std::ostream)
- [ ] cât mai multe `const` (unde este cazul)
- [ ] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe
  - nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [ ] scenariu de utilizare a claselor definite:
  - preferabil sub formă de teste unitare, mai ales dacă vorbim de aplicații consolă 
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [ ] tag de `git`: de exemplu `v0.1`
- [ ] serviciu de integrare continuă (CI); exemplu: GitHub Actions

## Milestone #2

#### Cerințe
- [ ] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [ ] moșteniri:
  - minim o clasă de bază și **3 clase derivate** din aceeași ierarhie
  - ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
  - [ ] funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază
    - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
    - constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei
    - afișare virtuală, interfață non-virtuală
  - [ ] apelarea constructorului din clasa de bază din constructori din derivate
  - [ ] clasă cu atribut de tip pointer la o clasă de bază cu derivate; aici apelați funcțiile virtuale prin pointer de bază, eventual prin interfața non-virtuală din bază
    - [ ] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
    - [ ] `dynamic_cast`/`std::dynamic_pointer_cast` pentru downcast cu sens
    - [ ] smart pointers (recomandat, opțional)
- [ ] excepții
  - [ ] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim **3** clase pentru erori specifice
  - [ ] utilizare cu sens: de exemplu, `throw` în constructor (sau funcție care întoarce un obiect), `try`/`catch` în `main`
  - această ierarhie va fi complet independentă de ierarhia cu funcții virtuale
- [ ] funcții și atribute `static`
- [ ] STL
- [ ] cât mai multe `const`
- [ ] funcții *de nivel înalt*, de eliminat cât mai mulți getters/setters/funcții low-level
- [ ] tag de `git`: de exemplu `v0.2`

## Milestone #3

#### Cerințe
- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o clasă șablon cu sens; minim **2 instanțieri**
  - [ ] preferabil și o funcție șablon (template) cu sens; minim 2 instanțieri
- [ ] tag de `git`: de exemplu `v0.3` sau `v1.0`

## Resurse
- adăugați trimiteri către resursele externe care v-au ajutat sau pe care le-ați folosit
