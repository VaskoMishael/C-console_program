#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void sum();

void driver();

void lap();

void gender();

void brand();

void year();

void average();

void under();

void change();

void newdriver();

void rmdriver();

int main(int argc, char const *argv[]) {
    char command;
    int true = 1;

    while (true) {
        printf("Enter your command please:");


        scanf("%c", &command);
        while (getchar() != '\n');

        switch (command) {

            case 's':
                sum();
                break;
            case 'd':
                driver();
                break;
            case 'l':
                lap();
                break;
            case 'g':
                gender();
                break;
            case 'b':
                brand();
                break;
            case 'y':
                year();
                break;
            case 'a':
                average();
                break;
            case 'u':
                under();
                break;
            case 'c':
                change();
                break;
            case 'n':
                newdriver();
                break;
            case 'r':
                rmdriver();
                break;
            case 'x':
                true = 0;
                break;
            default:
                printf("Can't recognise your command.\n");
                break;
        }
    }
    return 0;
}

void sum() {
    char buff, buffStrings;
    int racers = 0, i = 0, j = 0, n = 0;

    FILE *f = fopen("C:\\Users\\Professional\\CLionProjects\\C99standart\\tabulka.csv", "r");
    if (f == NULL) {
        printf("Subor nie je mozne precitat.");
    }
    while ((buffStrings = getc(f)) != EOF) {
        if (buffStrings == '\n') {
            ++racers;
        }
    }
    racers = racers + 1;
    rewind(f);
    char data[racers][10][50];

    while ((buff = getc(f)) != EOF) {
        if (buff == '\n') {
            data[i][j][n] = '\0';
            i++;
            n = 0;
            j = 0;
        } else if (buff == ' ' || buff == ';') {
//            while ((buff = getc(f)) != ' ')  { steps++; }
//            if (fseek(f, steps, SEEK_CUR) == ' ') { continue; }
            data[i][j][n] = '\0';
            j++;
            n = 0;
        } else {
            data[i][j][n] = buff;
            n++;
        }
    }
    data[i][j][n] = '\0';
    for (i = 0; i < racers; i++) {
        if (data[i][2][0] == 'm') {
            strcpy(data[i][2], "muz");
        } else {
            strcpy(data[i][2], "zena");
        }
    }
    for (i = 0; i < racers; i++) {
        printf("%s %s, nar. %s, %s, Atomobil: %s \nCasy okruhov: %s;%s;%s;%s;%s\n", data[i][0], data[i][1], data[i][3],
               data[i][2],
               data[i][4], data[i][5], data[i][6], data[i][7], data[i][8], data[i][9]);
    }
    fclose(f);
}

void driver() {
    char buff, buffStrings, surname[50];
    int racers = 0, i = 0, j = 0, n = 0, number, found;
    float awgLap = 0, bestLap = 1000, worstLap = 0;

    FILE *f = fopen("C:\\Users\\Professional\\CLionProjects\\C99standart\\tabulka.csv", "r");
    if (f == NULL) {
        printf("Subor nie je mozne precitat.");
    }
    while ((buffStrings = getc(f)) != EOF) {
        if (buffStrings == '\n') {
            ++racers;
        }
    }
    racers = racers + 1;
    rewind(f);
    char data[racers][10][50];

    while ((buff = getc(f)) != EOF) {
        if (buff == '\n') {
            data[i][j][n] = '\0';
            i++;
            n = 0;
            j = 0;
        } else if (buff == ' ' || buff == ';') {
            data[i][j][n] = '\0';
            j++;
            n = 0;
        } else {
            data[i][j][n] = buff;
            n++;
        }
    }
    data[i][j][n] = '\0';
    printf("Zadajte priezvisko jazdca:");
    scanf("%s", surname);
    while (getchar() != '\n');
    for (int i = 0; i < racers; i++) {
        if (strcmp(data[i][1], surname) == 0) {
            number = i;
            found = 1;
            break;
        } else found = 0;
    }
    if (found == 0) {
        printf("Cant find this racer, try again\n");
        return;
    }

    for (i = 0; i < racers; i++) {
        if (data[number][2][0] == 'm') {
            strcpy(data[number][2], "muz");
        } else {
            strcpy(data[number][2], "zena");
        }
    }
    float lap1 = atof(data[number][5]);
    float lap2 = atof(data[number][6]);
    float lap3 = atof(data[number][7]);
    float lap4 = atof(data[number][8]);
    float lap5 = atof(data[number][9]);
    awgLap = (lap5 + lap4 + lap3 + lap2 + lap1) / 5;

    printf("%s %s\nnar. %s, %s\nAutomobil: %s\n \nCasy okruhov: %.3f;%.3f;%.3f;%.3f;%.3f \n \n",
           data[number][0], data[number][1], data[number][3], data[number][2], data[number][4], lap1, lap2, lap3, lap4,
           lap5);

    for (int b = 5; b < 10; b++) {
        if (bestLap > atof(data[number][b])) {
            bestLap = atof(data[number][b]);
        }
    }
    printf("Najlepsie kolo: %.3f\n", bestLap);
    worstLap = bestLap;
    for (int b = 5; b < 10; b++) {
        if (worstLap < atof(data[number][b])) {
            worstLap = atof(data[number][b]);
        }
    }
    printf("Najhorsie kolo: %.3f\n", worstLap);
    printf("Priemerne kolo:%.3f\n", awgLap);
    fclose(f);
}

void lap() {
    char buff, buffStrings;
    int racers = 0, i = 0, j = 0, n = 0, racer, number;
    float bestLap = 1000;

    FILE *f = fopen("C:\\Users\\Professional\\CLionProjects\\C99standart\\tabulka.csv", "r");
    if (f == NULL) {
        printf("Subor nie je mozne precitat.");
    }
    while ((buffStrings = getc(f)) != EOF) {
        if (buffStrings == '\n') {
            ++racers;
        }
    }
    racers = racers + 1;
    rewind(f);
    char data[racers][10][50];

    while ((buff = getc(f)) != EOF) {
        if (buff == '\n') {
            data[i][j][n] = '\0';
            i++;
            n = 0;
            j = 0;
        } else if (buff == ' ' || buff == ';') {
            data[i][j][n] = '\0';
            j++;
            n = 0;
        } else {
            data[i][j][n] = buff;
            n++;
        }
    }
    data[i][j][n] = '\0';
    rewind(f);
    for (int k = 0; k < racers; k++) {
        for (int l = 5; l < 10; l++) {
            if (bestLap > atof(data[k][l])) {
                bestLap = atof(data[k][l]);
                number = l - 4;
                racer = k;
            }
        }
    }
    printf("Najlepsie kolo: %.3f\nJazdec:%s %s\nCislo kola:%d\n", bestLap, data[racer][0], data[racer][1], number);
    fclose(f);
}

void gender() {
    char buff, buffStrings, gender;
    int racers = 0, i = 0, j = 0, n = 0, racer, number;
    float bestLap = 1000;


    FILE *f = fopen("C:\\Users\\Professional\\CLionProjects\\C99standart\\tabulka.csv", "r");
    if (f == NULL) {
        printf("Subor nie je mozne precitat.");
    }
    while ((buffStrings = getc(f)) != EOF) {
        if (buffStrings == '\n') {
            ++racers;
        }
    }
    racers = racers + 1;
    rewind(f);
    char data[racers][10][50];

    while ((buff = getc(f)) != EOF) {
        if (buff == '\n') {
            data[i][j][n] = '\0';
            i++;
            n = 0;
            j = 0;
        } else if (buff == ' ' || buff == ';') {
            data[i][j][n] = '\0';
            j++;
            n = 0;
        } else {
            data[i][j][n] = buff;
            n++;
        }
    }
    data[i][j][n] = '\0';
    rewind(f);
    printf("zadajte pohlavie jazdca:\n");
    scanf("%c", &gender);
    while (getchar() != '\n');
    if (gender == 'm' | gender == 'f') {
    } else {
        printf("Nepovolena hodnota\n");
        return;
    }
    for (int k = 0; k < racers; k++) {
        for (int l = 5; l < 10; l++) {
            if (bestLap > atof(data[k][l])) {
                if (data[k][2][0] == gender) {
                    bestLap = atof(data[k][l]);
                    number = l - 4;
                    racer = k;
                }
            }
        }
    }
    printf("Najlepsie kolo: %.3f\nJazdec: %s %s\nCislo kola: %d\n", bestLap, data[racer][0], data[racer][1], number);
    fclose(f);
}

void brand() {
    char buff, buffStrings, porsche[] = "porsche", bugatti[] = "bugatti", honda[] = "honda", ferrari[] = "ferrari";
    int racers = 0, i = 0, j = 0, n = 0, porscheRacer, bugattiRacer, hondaRacer, ferrariRacer, porscheNumber, bugattiNumber, hondaNumber, ferrariNumber;
    float porscheLap = 100000, bugattiLap = 100000, hondaLap = 100000, ferrariLap = 100000;


    FILE *f = fopen("C:\\Users\\Professional\\CLionProjects\\C99standart\\tabulka.csv", "r");
    if (f == NULL) {
        printf("Subor nie je mozne precitat.");
    }
    while ((buffStrings = getc(f)) != EOF) {
        if (buffStrings == '\n') {
            ++racers;
        }
    }
    racers = racers + 1;
    rewind(f);
    char data[racers][10][50];

    while ((buff = getc(f)) != EOF) {
        if (buff == '\n') {
            data[i][j][n] = '\0';
            i++;
            n = 0;
            j = 0;
        } else if (buff == ' ' || buff == ';') {
            data[i][j][n] = '\0';
            j++;
            n = 0;
        } else {
            data[i][j][n] = buff;
            n++;
        }
    }
    data[i][j][n] = '\0';
    for (int k = 0; k < racers; k++) {
        for (int l = 5; l < 10; l++) {
            if (porscheLap > atof(data[k][l])) {
                if ((strcmp(data[k][4], porsche)) == 0) {
                    porscheLap = atof(data[k][l]);
                    porscheNumber = l - 4;
                    porscheRacer = k;
                }
            }
        }
    }
    for (int k = 0; k < racers; k++) {
        for (int l = 5; l < 10; l++) {
            if (bugattiLap > atof(data[k][l])) {
                if ((strcmp(data[k][4], bugatti)) == 0) {
                    bugattiLap = atof(data[k][l]);
                    bugattiNumber = l - 4;
                    bugattiRacer = k;
                }
            }
        }
    }
    for (int k = 0; k < racers; k++) {
        for (int l = 5; l < 10; l++) {
            if (hondaLap > atof(data[k][l])) {
                if ((strcmp(data[k][4], honda)) == 0) {
                    hondaLap = atof(data[k][l]);
                    hondaNumber = l - 4;
                    hondaRacer = k;
                }
            }
        }
    }
    for (int k = 0; k < racers; k++) {
        for (int l = 5; l < 10; l++) {
            if (ferrariLap > atof(data[k][l])) {
                if ((strcmp(data[k][4], ferrari)) == 0) {
                    ferrariLap = atof(data[k][l]);
                    ferrariNumber = l - 4;
                    ferrariRacer = k;
                }
            }
        }
    }
    if (bugattiLap == 100000) {
        printf("Znacka: bugatti\nNajlepsie kolo: ---\nJazdec: ---\nCislo kola: ---\n \n");
    } else {
        printf("Znacka: bugatti\nNajlepsie kolo: %.3f\nJazdec: %s %s\nCislo kola: %d\n \n", bugattiLap,
               data[bugattiRacer][0],
               data[bugattiRacer][1], bugattiNumber);
    }
    if (ferrariLap == 100000) {
        printf("Znacka: ferrari\nNajlepsie kolo: ---\nJazdec: ---\nCislo kola: ---\n \n");
    } else {
        printf("Znacka: ferrari\nNajlepsie kolo: %.3f\nJazdec: %s %s\nCislo kola: %d\n \n", ferrariLap,
               data[ferrariRacer][0],
               data[ferrariRacer][1], ferrariNumber);
    }

    if (hondaLap == 100000) {
        printf("Znacka: honda\nNajlepsie kolo: ---\nJazdec: ---\nCislo kola: ---\n \n");
    } else {
        printf("Znacka: honda\nNajlepsie kolo: %.3f\nJazdec: %s %s\nCislo kola: %d\n \n", hondaLap, data[hondaRacer][0],
               data[hondaRacer][1], hondaNumber);
    }
    if (porscheLap == 100000) {
        printf("Znacka: porsche\nNajlepsie kolo: ---\nJazdec: ---\nCislo kola: ---\n \n");
    } else {
        printf("Znacka: porsche\nNajlepsie kolo: %.3f\nJazdec: %s %s\nCislo kola: %d\n \n", porscheLap,
               data[porscheRacer][0],
               data[porscheRacer][1], porscheNumber);
    }
    fclose(f);
}

void year() {
    char buff, buffStrings;
    int racers = 0, i = 0, j = 0, n = 0, number, year;

    FILE *f = fopen("C:\\Users\\Professional\\CLionProjects\\C99standart\\tabulka.csv", "r");
    if (f == NULL) {
        printf("Subor nie je mozne precitat.");
    }
    while ((buffStrings = getc(f)) != EOF) {
        if (buffStrings == '\n') {
            ++racers;
        }
    }
    racers = racers + 1;
    rewind(f);
    char data[racers][10][50];

    while ((buff = getc(f)) != EOF) {
        if (buff == '\n') {
            data[i][j][n] = '\0';
            i++;
            n = 0;
            j = 0;
        } else if (buff == ' ' || buff == ';') {
            data[i][j][n] = '\0';
            j++;
            n = 0;
        } else {
            data[i][j][n] = buff;
            n++;
        }
    }
    data[i][j][n] = '\0';
    printf("Zadajte rok:\n");
    scanf("%d", &year);
    while (getchar() != '\n');

    for (int m = 0; m < racers; m++) {
        if (atoi(data[m][3]) < year) {
            for (int l = 6; l < 10; l++) {
                if (atof(data[m][5]) > atof(data[m][l])) {
                    strcpy(data[m][5], data[m][l]);
                    number = l - 4;
                }
            }
            printf("%s %s\nnar. %s\nNajlepsie kolo: %.3f\nCislo kola: %d\n\n", data[m][0], data[m][1], data[m][3],
                   atof(data[m][5]), number);
        }
    }
fclose(f);
}

void average() {
    char buff, buffStrings;
    int racers = 0, i = 0, j = 0, n = 0, bestRacer;
    float average, bestAverage = 100000;


    FILE *f = fopen("C:\\Users\\Professional\\CLionProjects\\C99standart\\tabulka.csv", "r");
    if (f == NULL) {
        printf("Subor nie je mozne precitat.");
    }
    while ((buffStrings = getc(f)) != EOF) {
        if (buffStrings == '\n') {
            ++racers;
        }
    }
    racers = racers + 1;
    rewind(f);
    char data[racers][10][50];

    while ((buff = getc(f)) != EOF) {
        if (buff == '\n') {
            data[i][j][n] = '\0';
            i++;
            n = 0;
            j = 0;
        } else if (buff == ' ' || buff == ';') {
            data[i][j][n] = '\0';
            j++;
            n = 0;
        } else {
            data[i][j][n] = buff;
            n++;
        }
    }
    data[i][j][n] = '\0';
    for (int k = 0; k < racers; k++) {
        average = (atof(data[k][5]) + atof(data[k][6]) + atof(data[k][7]) + atof(data[k][8]) + atof(data[k][9])) / 5;
        printf("%s %s - %0.3f\n", data[k][0], data[k][1], average);
        if (bestAverage > average) {
            bestAverage = average;
            bestRacer = k;
        }
    }
    printf("\nNajlepsie:\n%s %s - %.3f\n", data[bestRacer][0], data[bestRacer][1], bestAverage);
    fclose(f);
}

void under() {
    char buff, buffStrings;
    int racers = 0, i = 0, j = 0, n = 0, lapsNumber = 0;
    float userLap;

    FILE *f = fopen("C:\\Users\\Professional\\CLionProjects\\C99standart\\tabulka.csv", "r");
    if (f == NULL) {
        printf("Subor nie je mozne precitat.");
    }
    while ((buffStrings = getc(f)) != EOF) {
        if (buffStrings == '\n') {
            ++racers;
        }
    }
    racers = racers + 1;
    rewind(f);
    char data[racers][10][50];

    while ((buff = getc(f)) != EOF) {
        if (buff == '\n') {
            data[i][j][n] = '\0';
            i++;
            n = 0;
            j = 0;
        } else if (buff == ' ' || buff == ';') {
            data[i][j][n] = '\0';
            j++;
            n = 0;
        } else {
            data[i][j][n] = buff;
            n++;
        }
    }
    data[i][j][n] = '\0';
    printf("Enter time of lap:");
    scanf("%f", &userLap);
    while (getchar() != '\n');

    int isWritten = 0;
    int r = 0;
    for (int k = 0; k < racers; k++) {
        for (int l = 5; l < 10; l++) {
            if (atof(data[k][l]) <= userLap) {
                lapsNumber++;
            }
        }
        for (int l = 5; l < 10; l++) {
            if (atof(data[k][l]) <= userLap) {
                if (isWritten == 0 && atof(data[k][l]) < userLap) {
                    printf("%s %s - %d kola,", data[k][0], data[k][1], lapsNumber);
                    isWritten = 1;
                }
                printf(" %d (%.3f)", l - 4, atof(data[k][l]));
                if (r < lapsNumber - 1) {
                    printf(",");
                    r++;
                }
            }
        }
        if (isWritten == 1) {
            printf("\n");
        }
        lapsNumber = 0;
        isWritten = 0;
        r = 0;
    }
    fclose(f);
}

void change() {
    char buff, buffStrings, surname[50], newTime;
    int racers = 0, i = 0, j = 0, n = 0, lapNumber, racerNumber, found, line = 0;
    FILE *f;

    f = fopen("C:\\Users\\Professional\\CLionProjects\\C99standart\\tabulka.csv", "r+");
    if (f == NULL) {
        printf("Subor nie je mozne precitat.");
    }
    while ((buffStrings = getc(f)) != EOF) {
        if (buffStrings == '\n') {
            ++racers;
        }
    }
    racers = racers + 1;
    rewind(f);
    char data[racers][10][50];

    while ((buff = getc(f)) != EOF) {
        if (buff == '\n') {
            data[i][j][n] = '\0';
            i++;
            n = 0;
            j = 0;
        } else if (buff == ' ' || buff == ';') {
            data[i][j][n] = '\0';
            j++;
            n = 0;
        } else {
            data[i][j][n] = buff;
            n++;
        }
    }
    data[i][j][n] = '\0';

    printf("Zadajte priezvisko jazdca:\n");
    scanf("%s", surname);
    while (getchar() != '\n');

    for (int i = 0; i < racers; i++) {
        if (strcmp(data[i][1], surname) == 0) {
            racerNumber = i;
            found = 1;
            break;
        } else found = 0;
    }
    if (found == 0) {
        printf("Cant find this racer, try again\n");
        return;
    }
    printf("Zadajte poradove cislo kola:\n");
    scanf("%d", &lapNumber);
    while (getchar() != '\n');

    printf("Zadajte novy cas:\n");
    scanf("%s", &newTime);
    while (getchar() != '\n');

    strcpy(data[racerNumber][lapNumber + 4], &newTime);
    rewind(f);
    fclose(f);
    f = fopen("C:\\Users\\Professional\\CLionProjects\\C99standart\\tabulka.csv", "w+");
    if (f == NULL) {
        printf("Subor nie je mozne precitat.");
    }

    for (int k = 0; k < racers; k++) {
        fprintf(f, "%s %s;%s;%s;%s;%s;%s;%s;%s;%s", data[k][0], data[k][1], data[k][2], data[k][3], data[k][4],
                data[k][5], data[k][6], data[k][7], data[k][8], data[k][9]);
        if (line < racers - 1) {
            fprintf(f, "\n");
            line++;
        }
    }

    for (i = 0; i < racers; i++) {
        if (data[i][2][0] == 'm') {
            strcpy(data[i][2], "muz");
        } else {
            strcpy(data[i][2], "zena");
        }
    }
    for (i = 0; i < racers; i++) {
        printf("%s %s, nar. %s, %s, Atomobil: %s \nCasy okruhov: %s;%s;%s;%s;%s\n", data[i][0], data[i][1], data[i][3],
               data[i][2],
               data[i][4], data[i][5], data[i][6], data[i][7], data[i][8], data[i][9]);
    }
    fclose(f);
}

void newdriver() {
    char buff, buffStrings, name[50], surname[50], gender, genderOutput[5], car[10], laps[50], born[5], ferrari[] = "ferrari", bugatti[] = "bugatti", honda[] = "honda", porsche[] = "porsche";
    int racers = 0, i = 0, j = 0, n = 0;

    FILE *f = fopen("C:\\Users\\Professional\\CLionProjects\\C99standart\\tabulka.csv", "r+");
    if (f == NULL) {
        printf("Subor nie je mozne precitat.");
    }
    while ((buffStrings = getc(f)) != EOF) {
        if (buffStrings == '\n') {
            ++racers;
        }
    }
    racers = racers + 1;
    rewind(f);
    char data[racers][10][50];

    while ((buff = getc(f)) != EOF) {
        if (buff == '\n') {
            data[i][j][n] = '\0';
            i++;
            n = 0;
            j = 0;
        } else if (buff == ' ' || buff == ';') {
            data[i][j][n] = '\0';
            j++;
            n = 0;
        } else {
            data[i][j][n] = buff;
            n++;
        }
    }
    data[i][j][n] = '\0';
    printf("Enter name and surname of racer:");
    scanf("%s %s", &name, &surname);
    while (getchar() != '\n');

    printf("Enter year of birth:");
    scanf("%s", &born);
    while (getchar() != '\n');
    if (atoi(born) < 1000 || atoi(born) > 9999) {
        printf("only YYYY format allowed\n");
        return;
    }
    printf("Enter gender:");
    scanf("%c", &gender);
    while (getchar() != '\n');
    if (gender == 'm' || gender == 'f') {
    } else {
        printf("Unknown gender, only 'm' or 'f' allowed.\n");
        return;
    }

    printf("Enter brand of car:");
    scanf("%s", &car);
    if (strcmp(car, ferrari) == 0 || strcmp(car, bugatti) == 0 || strcmp(car, honda) == 0 ||
        strcmp(car, porsche) == 0) {}
    else {
        printf("Forbidden brand\n");
        return;
    }
    while (getchar() != '\n');

    printf("Enter time of laps divided with semicolon:");
    scanf("%s", &laps);
    while (getchar() != '\n');

    fprintf(f, "\n%s %s;%c;%s;%s;%s", name, surname, gender, born, car, laps);

    for (i = 0; i < racers; i++) {
        if (data[i][2][0] == 'm') {
            strcpy(data[i][2], "muz");
        } else {
            strcpy(data[i][2], "zena");
        }
    }
    for (i = 0; i < racers; i++) {
        printf("%s %s, nar. %s, %s, Atomobil: %s \nCasy okruhov: %s;%s;%s;%s;%s\n", data[i][0], data[i][1],
               data[i][3],
               data[i][2],
               data[i][4], data[i][5], data[i][6], data[i][7], data[i][8], data[i][9]);
    }

    if (gender == 'm') {
        strcpy(genderOutput, "muz");
    } else strcpy(genderOutput, "zena");
    printf("%s %s, nar. %s, %s, Atomobil: %s \nCasy okruhov: %s\n", name, surname, born, genderOutput, car, laps);

    fclose(f);
}

void rmdriver() {
    char buff, buffStrings, name[50], surname[50], gender, genderOutput[5], car[10], laps[50], born[5], ferrari[] = "ferrari", bugatti[] = "bugatti", honda[] = "honda", porsche[] = "porsche";
    int racers = 0, i = 0, j = 0, n = 0, lapsNumber = 0, number, found, line = 0;
    FILE *f;
    f = fopen("C:\\Users\\Professional\\CLionProjects\\C99standart\\tabulka.csv", "r");
    if (f == NULL) {
        printf("Subor nie je mozne precitat.");
    }
    while ((buffStrings = getc(f)) != EOF) {
        if (buffStrings == '\n') {
            ++racers;
        }
    }
    racers = racers + 1;
    rewind(f);
    char data[racers][10][50];

    while ((buff = getc(f)) != EOF) {
        if (buff == '\n') {
            data[i][j][n] = '\0';
            i++;
            n = 0;
            j = 0;
        } else if (buff == ' ' || buff == ';') {
            data[i][j][n] = '\0';
            j++;
            n = 0;
        } else {
            data[i][j][n] = buff;
            n++;
        }
    }
    data[i][j][n] = '\0';
    printf("Zadajte priezvisko jazdca:");
    scanf("%s", surname);
    while (getchar() != '\n');
    for (int i = 0; i < racers; i++) {
        if (strcmp(data[i][1], surname) == 0) {
            number = i;
            found = 1;
            break;
        } else found = 0;
    }
    if (found == 0) {
        printf("Cant find this racer, try again\n");
        return;
    }
    printf("Jazdec s menom \"%s %s\" bol vymazany.\n", data[number][0], data[number][1]);
    fclose(f);
    f = fopen("C:\\Users\\Professional\\CLionProjects\\C99standart\\tabulka.csv", "w+");
    if (f == NULL) {
        printf("Subor nie je mozne precitat.");
    }
    for (int k = 0; k < racers; k++) {
        if (k == number) {
        } else {
            fprintf(f, "%s %s;%s;%s;%s;%s;%s;%s;%s;%s", data[k][0], data[k][1], data[k][2], data[k][3], data[k][4],
                    data[k][5], data[k][6], data[k][7], data[k][8], data[k][9]);
            if (line < racers - 2) {
                fprintf(f, "\n");
                line++;
            }
        }
    }
    fclose(f);
}