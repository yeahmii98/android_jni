package com.example.afinal;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Toast;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;

import com.google.zxing.integration.android.IntentIntegrator;
import com.google.zxing.integration.android.IntentResult;

import org.json.JSONException;
import org.json.JSONObject;

public class QRScanActivity extends AppCompatActivity {
    private IntentIntegrator qrScan;

    protected void onCreate(Bundle savedInstanceStare) {
        super.onCreate(savedInstanceStare);

        //actionBar 숨김
        ActionBar actionBar = getSupportActionBar();
        actionBar.hide();

        //QR 실행시킴
        qrScan = new IntentIntegrator(this);
        qrScan.setOrientationLocked(false);
        qrScan.setPrompt("네모칸에 QR코드를 맞춰주세요");
        qrScan.initiateScan();
    }
//    @Override
//    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
//        IntentResult result = IntentIntegrator.parseActivityResult(requestCode, resultCode, data);
//        if(result != null) {
//            if(result.getContents() == null) {
//                Toast.makeText(this, "Cancelled", Toast.LENGTH_LONG).show();
//                // todo
//            } else {
//                Toast.makeText(this, "Scanned: " + result.getContents(), Toast.LENGTH_LONG).show();
//                JSONObject obj = new JSONObject(result.getContents());
//                String pubKeyString = obj.getString("K");
//                Toast.makeText(MainActivity.this, pubKeyString, Toast.LENGTH_LONG).show();
//                // todo
//            }
//        } else {
//            super.onActivityResult(requestCode, resultCode, data);
//        }
//    }


}
