package com.example.opencvstudysource;

/**
 * Created by Zack on 1/3/2018.
 */

public class NDKUtils {

    NDKUtils(){
        System.loadLibrary("native-lib");
    }
    public native int[] gray(int[] buf, int w, int h);
}
