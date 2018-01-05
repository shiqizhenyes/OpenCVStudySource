package com.example.opencvstudysource;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.widget.ImageView;

/**
 * Created by Zack on 1/4/2018.
 *
 */

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ImageView iv = findViewById(R.id.iv);
        NDKUtils ndkUtils = new NDKUtils();
        Bitmap bitmap = BitmapFactory.decodeResource(getResources(),R.drawable.koala);
        Bitmap greyBitmap =  Bitmap.createBitmap(bitmap.getWidth(),bitmap.getHeight(), Bitmap.Config.RGB_565);
        int w = bitmap.getWidth();
        int h = bitmap.getHeight();
        int[] buf = new int[w * h];
        bitmap.getPixels(buf,0,w,0,0, w, h);
        int[] greyPix = ndkUtils.gray(buf,w,h);
        greyBitmap.setPixels(greyPix,0, w,0,0, w, h);
        iv.setImageBitmap(greyBitmap);
    }

}
