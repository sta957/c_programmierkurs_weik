package com.company;

public class Konto {
    private double kontostand = 0.0;
    private String inhaber = "";
    private int code = 0;
    private int kontonummer;


    public Konto(double ks, String in){
        kontostand = ks;
        inhaber = in;
    }

    public Konto(double ks, String in, int wc, int kn){
        kontostand = ks;
        inhaber = in;
        code = wc;
    }

    public double getKontostand(){
        return this.kontostand;
    }

    public String getInhaber(){
        return this.inhaber;
    }

    public double abheben(double Summe){
        this.kontostand -= Summe;
        return kontostand;
    }

    public double einzahlen(double Summe){
        this.kontostand += Summe;
        return kontostand;
    }

    public double ueberweisen(double Summe, Konto Kontonummer){
        kontostand = this.abheben(Summe);
        Kontonummer.einzahlen(Summe);
        return kontostand;
    }
}
