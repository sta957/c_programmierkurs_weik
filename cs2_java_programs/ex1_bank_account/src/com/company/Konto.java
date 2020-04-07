package com.company;

public class Konto {
    private double kontostand = 0.0;
    private Inhaber inhaber;
    private Konto code;
    private int kontonummer;

    public Konto(Inhaber in, int kn){
        this.kontonummer = kn;
        this.inhaber = in;
    }

    public Konto(double ks, Inhaber in, int kn){
        this.kontostand = ks;
        this.inhaber = in;
        this.kontonummer = kn;
    }

    public Konto(double ks, Inhaber in, Konto wc, int kn){
        this.kontostand = ks;
        this.inhaber = in;
        this.code = wc;
        this.kontonummer = kn;
        if(!code.getInhaber().equals("")){
            //System.out.println(code.getKontostand());
            System.out.println(code.einzahlen(60));
            //System.out.println(code.getKontostand());
        }
    }

    public double getKontostand(){
        return this.kontostand;
    }

    public String getInhaber(){
        return this.inhaber.getVorname();
    }

    public int abheben(double summe){
        if(summe > 0 && summe <= this.kontostand) {
            this.kontostand -= summe;
            return 1;
        }else{
            return 0;
        }
    }

    public int einzahlen(double summe){
        if(summe > 0) {
            this.kontostand += summe;
            return 1;
        }else{
            return 0;
        }
    }

    public int ueberweisen(double summe, Konto Zielkonto){
        if(summe <= this.kontostand){
            this.abheben(summe);
            Zielkonto.einzahlen(summe);
            return 1;
        }else{
            return 0;
        }
    }
}
