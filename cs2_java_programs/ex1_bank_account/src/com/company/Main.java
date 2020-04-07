package com.company;

public class Main {

    public static void main(String[] args){
        Konto Kontonummer[] = new Konto[1000];
        Kontonummer[1234] = new Konto(100.0, "Timo", 1337, 1234);
        Kontonummer[2345] = new Konto(20.0, "Peter", 1234, 1337);
	    int Eingabe = abfrageMain();
	    double Summe = 0.0;
        System.out.println("Bitte geben Sie eine Kontonummer ein\n");
        int nr = Integer.parseInt(System.console().readLine());
	    System.out.println("\nWillkommen in Ihrem Konto. Was kann Ich für Sie tun?\n");

        switch(Eingabe){
           case 1: System.out.println("Ihr Guthaben beträgt " + Kontonummer[nr].getKontostand() + " €\n");
                    abfrageMain();break;
            case 2: System.out.println("Der Inhaber des Kontos ist " + Kontonummer[nr].getInhaber() + ".\n");
                    abfrageMain();break;
            case 3: System.out.println("Wie viel möchten Sie einzahlen?\n");
                    Summe = Double.parseDouble(System.console().readLine());
                    Kontonummer[nr].einzahlen(Summe);
                    System.out.println("\nSie haben " + Summe + " € eingezahlt.\n");
                    System.out.println("Ihr neuer Kontostand beträgt " + Kontonummer[nr].getKontostand() + " €\n");
                    abfrageMain();break;
            case 4: System.out.println("Wie viel möchten Sie abheben?\n");
                    Summe = Double.parseDouble(System.console().readLine());
                Kontonummer[nr].abheben(Summe);
                    System.out.println("\nSie haben " + Summe + " € abgehoben.\n");
                    System.out.println("Ihr neuer Kontostand beträgt " + Kontonummer[nr].getKontostand() + " €\n");
                    abfrageMain();break;
            case 5: System.out.println("Wie viel möchten Sie überweisen?\n");
                    Summe = Double.parseDouble(System.console().readLine());
                    System.out.println("An welche Kontonummer möchten Sie überweisen?\n");
                    int x = Integer.parseInt(System.console().readLine());
                Kontonummer[nr].ueberweisen(Summe, Kontonummer[x]);
                    System.out.println("\nEs wurden " + Summe + " € an " + Kontonummer + " überwiesen.\n");
                    System.out.println("Ihr neuer Kontostand beträgt " + Kontonummer[nr].getKontostand() + " €\n");
                    abfrageMain();break;
            case 9: System.exit(0);break;
            default: abfrageMain();
        }

        Kontonummer[nr].getKontostand();

    }

    public static int abfrageMain() {
        System.out.println("1 - Kontostand abfragen\n");
        System.out.println("2 - Inhaber abfragen\n");
        System.out.println("3 - Geld einzahlen\n");
        System.out.println("4 - Geld abheben\n");
        System.out.println("5 - Geld überweisen\n");
        System.out.println("9 - Programm beenden\n");
        int Output = Integer.parseInt(System.console().readLine());
        return Output;
    }
}
