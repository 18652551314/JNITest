package com.example.android.test;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(testFrom() + "\n"
                + stringFromJNI() + "\n"
                + test2FromJNI("listen") + "\n"
                + test3FromJNI(10000) + "\n"
                + test4FromJNI(3.1415926)
        );
    }



    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String testFrom();

    public native String stringFromJNI();

    public native String test2FromJNI(String val);

    public native String test3FromJNI(int val);

    public native double test4FromJNI(double v);

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
}
