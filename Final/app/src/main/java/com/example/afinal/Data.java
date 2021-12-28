package com.example.afinal;

public class Data {
    private String MAC;
    private String boot_pk;
    private int number;

    public String getMAC(){
        return  MAC;
    }

    public void setMAC(String MAC){
        this.MAC = MAC;
    }

    public String getBoot_pk(){
        return boot_pk;
    }

    public void setBoot_pk(String boot_pk){
        this.boot_pk = boot_pk;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }
}
