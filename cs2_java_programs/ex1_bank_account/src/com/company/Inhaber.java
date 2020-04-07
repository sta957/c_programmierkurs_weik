package com.company;

public class Inhaber {
    private String nachname;
    private String vorname;
    private String addresse;

    public Inhaber(String nn, String vn, String ad){
        this.nachname = nn;
        this.vorname = vn;
        this.addresse = ad;
    }

    public String getNachname(){
        return this.nachname;
    }
    public String getVorname(){
        return this.vorname;
    }
    public String getAddresse(){
        return this.addresse;
    }
}
