#include "vektoriai.h"
#include "failu-generavimas.h"
#include "student.h"
void generatingFinal();

int main() {
    int numStudents = 0;
    vector<Student> students;
    string input, grade, finalExamGrade, choice, option, line, filename;

    cout << "0 - Tikrinti Rule of Five ir I&O \n" << "1 - Jei norite generuoti failus \n" << "2 - Jei norite nuskaityti iš failo \n" << "3 - Jei norite vesti duomenis \n" << "4 - Jei norite išeiti \n";;
    cin >> option; 

switch (option [0]){
    case '0' :
        tests();
        cout << "1 - Jei norite generuoti failus \n" << "2 - Jei norite nuskaityti iš failo \n" << "3 - Jei norite vesti duomenis \n" << "4 - Jei norite išeiti \n";;
        cin >> option;
    case '1' :
        generatingFinal();
        exit(EXIT_FAILURE);
    case '2' :
    cout << "Iš kurio failo norite nuskaityti?" << endl;
    cout << "1 - studentai10000.txt" << endl;
    cout << "2 - studentai100000.txt" << endl;
    cout << "3 - studentai1000000.txt" << endl;
    cout << "4 - kursiokai.txt" << endl;
    char fileOption;
    cin >> fileOption;

    switch (fileOption) {
        case '1':
            filename = "studentai10000.txt";
            break;
        case '2':
            filename = "studentai100000.txt";
            break;
        case '3':
            filename = "studentai1000000.txt";
            break;
        case '4':
            filename = "kursiokai.txt";
            break;
        default:
            cout << "Neteisinga įvestis. Turite įrašyti 1/2/3/4." << endl;
            return 1;
    }

    readFromFile(filename, students);

    cout << "Kaip norėtumėte surikiuoti rezultatus?" << endl;
    cout << "1 - Pagal vardą ir pavardę" << endl;
    cout << "2 - Pagal vidurkį (nuo didžiausio)" << endl;
    cout << "3 - Pagal medianą (nuo didžiausios)" << endl;
    char sortingOption;
    cin >> sortingOption;

   
    sortStudents(students, sortingOption);

    cout << "Kaip norėtumėte išvesti rezultatus?" << endl;
    cout << "1 - Į ekraną" << endl;
    cout << "2 - Į failą 'results.txt'" << endl;
    cin >> fileOption;

    if (fileOption == '2') {
        printResults(students, sortingOption, "results.txt");
    } else if (fileOption == '1'){
        printResults(students, sortingOption, "");
    }
    else {
        cout << "Neteisinga įvestis. Turite įrašyti 1 arba 2" << endl;
        exit(EXIT_FAILURE);
    }
            break;

    case '3' :
        try{
            while (true) {
            cout << "Ar norite generuoti studento vardą ir pavardę ar įvesti ranka? (g/r): \n"
                         << "Įveskite 'baigti', kai norėsite baigti įvestį \n"
                         << "Įveskite 'iseiti', jei norite išeiti \n";       
            cin >> choice;
        if (choice == "iseiti") { 
            return 0;
        }
        if (choice == "baigti") {
            if (numStudents == 0) {
                cout << "Programa baigta.\n";
                return 0; 
            } else {
                break; 
            }
        }
        string firstName, lastName;
        Student temp;
        switch (choice[0]) {
            case 'r':
            while(true){
                    cout << "Įveskite studento vardą ir pavardę :\n";
                    cin >> firstName >> lastName;
                    if (firstName == "iseiti") { 
                        return 0;
                    }
                    if (firstName == "baigti") {
                        if (numStudents == 0) {
                            cout << "Programa baigta.\n";
                            return 0; 
                        } else {
                            break; 
                        }
                    }
                    if (!isValidName(firstName) || !isValidName(lastName)) {
                        cout << "Neteisinga įvestis. Vardas ir pavardė turėtų būti sudaryti bent iš 2 raidžių. \n";
                        continue;
                    }
                    break;
        }
            temp.setFirstName(firstName);
            temp.setLastName(lastName);

                    cout << "Ar norite vesti namų darbų pažymius ranka ar generuoti? (r/g): ";
                    cin >> input;
                    if (input == "r") {
                    cout << "Įveskite namų darbų pažymius " << temp.getFirstName() << ' ' << temp.getLastName() << " (įveskite '-1', kad baigti):\n";
        while (cin >> grade) {
                if (grade == "-1") {
                    break;
                }
                if (isValidGrade(grade)) {
            vector<int> grades = temp.getGrades(); 
            grades.push_back(stoi(grade)); 
            temp.setGrades(grades);              
                     } 
            else {
                    cout << "Neteisinga įvestis. Pažymiai gali būti tik skaičiai nuo 1 iki 10. " << endl;
                }
         }
        
            while (true) {
            cout << "Įveskite egzamino pažymį " << temp.getFirstName() << ' ' << temp.getLastName() << ":\n";
            cin >> finalExamGrade;
            if (isValidGrade(finalExamGrade)) {
                temp.setFinalExamGrade(stoi(finalExamGrade));
                numStudents++;
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Neteisinga įvestis. Egzamino pažymys gali būti tik skaičius nuo 1 iki 10." << endl;
            }
     }
 }      else if (input == "g") {
    int number;
    while (true) {
        try {
            cout << "Kiek namų darbų pažymių norite generuoti? ";
            cin >> number;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Neteisinga įvestis. Įveskite skaičių.");
            }
            if (number < 0) {
                throw runtime_error("Neteisinga įvestis. Įveskite teigiamą skaičių.");
            }
            break;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
    randomGradeGenerator(number, temp); 
    numStudents++;
} 
                     else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Neteisinga įvestis. Įveskite 'r' arba 'g'.\n";
                        exit(EXIT_FAILURE);
                    }
                students.push_back(temp);
                break;

            case 'g':
            generateNames(temp);
            cout << "Ar norite vesti namų darbų pažymius ranka ar generuoti? (r/g): ";
                    cin >> input;
                    if (input == "r") {
        cout << "Įveskite namų darbų pažymius " << temp.getFirstName() << ' ' << temp.getLastName() << " (įveskite '-1', kad baigti):\n";
    while (cin >> grade) {
                if (grade == "-1") {
                    break;
                }
                if (isValidGrade(grade)) {
            vector<int> grades = temp.getGrades(); // Get current grades
            grades.push_back(stoi(grade)); // Add new grade
            temp.setGrades(grades); 
                } else {
                    cout << "Neteisinga įvestis. Pažymiai gali būti tik skaičiai nuo 1 iki 10. " << endl;
                }
         }
         
        while (true) {
        cout << "Įveskite egzamino pažymį " << temp.getFirstName() << ' ' << temp.getLastName() << ":\n";
        cin >> finalExamGrade;
            if (isValidGrade(finalExamGrade)) {
            temp.setFinalExamGrade(stoi(finalExamGrade));
            numStudents++;
                break;
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Neteisinga įvestis. Egzamino pažymys gali būti tik skaičius nuo 1 iki 10." << endl;
            }
     }

 } else if (input == "g") {
    int number;
    while (true) {
        try {
            cout << "Kiek namų darbų pažymių norite generuoti? ";
            cin >> number;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Neteisinga įvestis. Įveskite skaičių.");
            }
            if (number < 0) {
                throw runtime_error("Neteisinga įvestis. Įveskite teigiamą skaičių.");
            }
            break;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }
    randomGradeGenerator(number, temp); 
    numStudents++;
} 
                 else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Neteisinga įvestis. Įveskite 'r' arba 'g'.\n";
                        exit(EXIT_FAILURE);
                    }
                students.push_back(temp);
                break;

            default:
                cout << "Neteisinga įvestis. Pasirinkite 'g' arba 'r'.\n";
                break;
        }
    }
      
                cout << fixed << setw(10) << "Vardas" << setw(20) << "Pavardė" << setw(25) << "Galutinis (Vid.)" << setw(25) << "Galutinis (Med.)\n";
                cout <<"--------------------------------------------------------------------------------------------\n";
                for (const auto& student : students) {
                    cout << fixed << setw(10) << student.getFirstName() << setw(20) << student.getLastName();
                    cout << fixed << setw(20) << setprecision(2)<< student.getAverage()*0.4+student.getFinalExamGrade() * 0.6;
                    cout << fixed << setw(25) << setprecision(2)<< student.getMedian()*0.4+student.getFinalExamGrade() * 0.6<< '\n';
                }

                 } catch (const exception& e) {
                    cerr << "Klaida: " << e.what() << endl;
                    return 1;
                }
            break; 

        case '4' :
        return 0;

        default:
            cout << "Neteisinga įvestis. Pasirinkite 1 arba 2.\n";
            break;
        }
        

    return 0;
}