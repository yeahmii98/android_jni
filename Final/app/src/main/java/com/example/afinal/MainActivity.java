package com.example.afinal;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.ItemTouchHelper;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.example.afinal.databinding.ActivityMainBinding;
import com.google.zxing.integration.android.IntentIntegrator;
import com.google.zxing.integration.android.IntentResult;

import org.json.JSONException;
import org.json.JSONObject;
import org.w3c.dom.Text;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'afinal' library on application startup.
    static {
        System.loadLibrary("afinal");
    }

    private Button qrscan_btn;
    private IntentIntegrator qrScan;
    private RecyclerAdapter adapter;
    private ItemTouchHelper helper;
    Data recyclerview_data = new Data();
    private TextView pubKey, MAC;

    //    public native void printJson();
    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        //actionBar 숨김
        ActionBar actionBar = getSupportActionBar();
        actionBar.hide();
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);

////        binding = ActivityMainBinding.inflate(getLayoutInflater());
////        setContentView(binding.getRoot());
//        setContentView(R.layout.activity_main);
//
//
////        // Example of a call to a native method
////        TextView tv = binding.sampleText;
////        TextView tv1 = binding.tvCalc;
//
//        //recyclerview
////        RecyclerView recyclerView = findViewById(R.id.recyclerView);
////        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(this);
////        recyclerView.setLayoutManager(linearLayoutManager);
////
////        adapter = new RecyclerAdapter();
////        recyclerView.setAdapter(adapter);
////        // swiper 구현
////        helper = new ItemTouchHelper(new ItemTouchHelperCallback(adapter));
////        helper.attachToRecyclerView(recyclerView);

        pubKey = (TextView) findViewById(R.id.boots_done);
        //QR Scanning Button 이벤트
        qrScan = new IntentIntegrator(this);
        qrscan_btn = findViewById(R.id.qrscan_btn);
        qrscan_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                qrScan.setBeepEnabled(false);
                qrScan.setOrientationLocked(false);
                qrScan.setPrompt("네모칸에 QR코드를 맞춰주세요");
                qrScan.initiateScan();
            }
        });


        //Configurator Process
//        TextView bootsText1 = findViewById(R.id.boots_done);
//        TextView bootsText2 = findViewById(R.id.boots_done);
//        TextView authText1 = findViewById(R.id.auth_done);
//        TextView authText2 = findViewById(R.id.auth_done);
//        String qr = "DPP:I:SN=4774LH2b4044;M:88366CFEF246;V:2;K:MFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEq0p8yeaU3flNjLkzjrqs4/nZNrB0tRE46VmBKA0QwNS7ESLkOxlLSV8dDmUns6cOrgx1tvH5heAqwMxAtle9zg==;;";
//        if (do_Bootstrapping(qr) == 0)
//        {
//            bootsText1.setText("Bootstrapping Done!!!");
//            if(do_Authentication() == 0)
//            {
//                authText1.setText("Authentication Done!!!");
//            }
//            else{
//                authText2.setText("Authentication Fail..");
//            }
//        }
//        else{
//            bootsText2.setText("Bootstrapping Fail..");
//        }

//        String qr = "DPP:I:SN=4774LH2b4044;M:88366CFEF246;V:2;K:MFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEq0p8yeaU3flNjLkzjrqs4/nZNrB0tRE46VmBKA0QwNS7ESLkOxlLSV8dDmUns6cOrgx1tvH5heAqwMxAtle9zg==;;";
//        String t = Integer.toString(getStatus());
//        tv2.setText(t);
////        tv.setText(stringFromJNI());
////        tv1.setText(stringFromBootstrapping());


//        printJson();
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        IntentResult result = IntentIntegrator.parseActivityResult(requestCode, resultCode, data);

        //result -> qr임
        if (result != null) {
            //qrcode 가 없으면
            if (result.getContents() == null) {
                Toast.makeText(MainActivity.this, "취소!", Toast.LENGTH_SHORT).show();
            } else {
                //qrcode 결과가 있으면
                Toast.makeText(MainActivity.this, "스캔완료!", Toast.LENGTH_SHORT).show();

                pubKey.setText(do_Scanning(result.getContents()));


                //                    pubKey = findViewById(R.id.boots_done);
//                    pubKey.setText(pubKeyString);
//                    textViewResult.setText(result.getContents());
                //data를 json으로 변환


//                    recyclerview_data.setMAC(obj.getString("MAC"));
//                    recyclerview_data.setBoot_pk(obj.getString("K"));
//                    adapter.addItem(recyclerview_data);
//                    adapter.notifyDataSetChanged();

            }
        }
        else {
            super.onActivityResult(requestCode, resultCode, data);
        }
    }
    /**
     * A native method that is implemented by the 'afinal' native library,
     * which is packaged with this application.
     */

    //    public native String stringFromJNI();
////    public native String stringFromHyunwooCustomizing();
////    public native String stringFromBootstrapping();
//    public native int getStrLen(String s);
    public native int do_Bootstrapping(String s);
    public native String do_Scanning(String s);
    public native int do_Authentication();
//    public native String getString(String s);

}