package com.company;
import java.util.Scanner;

public class Main {

    public static void main(String[] args){
        Inhaber piotr = new Inhaber("Michaelski", "Piotr", "NYC");
        Inhaber moby = new Inhaber("Dick", "Moby", "Rom");
        Konto Kontonummer[] = new Konto[10000];
        Kontonummer[1337] = new Konto(moby, 1337);
        Kontonummer[1234] = new Konto(100.0, piotr, Kontonummer[1337], 1234);

	    int Eingabe = 0;
	    double Summe = 0.0;
	    Scanner sc = new Scanner(System.in);
	    int z;

        System.out.println("Bitte geben Sie eine Kontonummer ein\n");
        int nr = Integer.parseInt(sc.nextLine());
	    System.out.println("\nWillkommen in Ihrem Konto. Was kann Ich für Sie tun?\n");

        do{
            Eingabe = abfrageMain();
            switch(Eingabe){
                case 1: System.out.println("Ihr Guthaben beträgt " + Kontonummer[nr].getKontostand() + " €\n");
                    break;
                case 2: System.out.println("Der Inhaber des Kontos ist " + Kontonummer[nr].getInhaber() + ".\n");
                    break;
                case 3: System.out.println("Wie viel möchten Sie einzahlen?");
                    Summe = Double.parseDouble(sc.nextLine());
                    z = Kontonummer[nr].einzahlen(Summe);
                    if(z == 1){
                        System.out.println("\nSie haben " + Summe + " € eingezahlt.");
                        System.out.println("Ihr neuer Kontostand beträgt " + Kontonummer[nr].getKontostand() + " €\n");
                    }else{
                        System.out.println("Fehler bei der Transaktion.\n");
                    }
                    break;
                case 4: System.out.println("Wie viel möchten Sie abheben?\n");
                    Summe = Double.parseDouble(sc.nextLine());
                    z = Kontonummer[nr].abheben(Summe);
                    if(z == 1){
                        System.out.println("\nSie haben " + Summe + " € abgehoben.");
                        System.out.println("Ihr neuer Kontostand beträgt " + Kontonummer[nr].getKontostand() + " €\n");
                    }else{
                        System.out.println("Fehler bei der Transaktion.\n");
                    }
                    break;
                case 5: System.out.println("Wie viel möchten Sie überweisen?");
                    Summe = Double.parseDouble(sc.nextLine());
                    System.out.println("An welche Kontonummer möchten Sie überweisen?");
                    int x = Integer.parseInt(sc.nextLine());
                    z = Kontonummer[nr].ueberweisen(Summe, Kontonummer[x]);
                    if(z == 1){
                        System.out.println("\nEs wurden " + Summe + " € an " + Kontonummer[x].getInhaber() + " überwiesen.");
                        System.out.println("Ihr neuer Kontostand beträgt " + Kontonummer[nr].getKontostand() + " €\n");
                    }else{
                        System.out.println("Ihr Kontoguthaben reicht für diese Transaktion nicht aus.\n");
                    }
                    break;
                case 9: System.exit(0);
            }
        }while(Eingabe != 9);
    }

    public static int abfrageMain() {
        System.out.println("1 - Kontostand abfragen");
        System.out.println("2 - Inhaber abfragen");
        System.out.println("3 - Geld einzahlen");
        System.out.println("4 - Geld abheben");
        System.out.println("5 - Geld überweisen");
        System.out.println("9 - Programm beenden\n");
        Scanner c = new Scanner(System.in);
        String input = c.nextLine();
        if(!input.equals("")){
            int Output = Integer.parseInt(input);
            return Output;
        }else{
            int Output = 0;
            return Output;
        }
    }
}
