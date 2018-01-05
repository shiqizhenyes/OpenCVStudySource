#include <jni.h>
#include <string>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"


using namespace cv;

extern "C"
JNIEXPORT jintArray JNICALL Java_com_example_opencvstudysource_NDKUtils_gray(
        JNIEnv *env, jclass obj, jintArray buf, int w, int h) {

    jint *cbuf;
    cbuf = env->GetIntArrayElements(buf, JNI_FALSE );
    if (cbuf == NULL) {
        return 0;
    }

    Mat imgData(h, w, CV_8UC4, (unsigned char *) cbuf);

    uchar* ptr = imgData.ptr(0);
    for(int i = 0; i < w*h; i ++){
        //计算公式：Y(亮度) = 0.299*R + 0.587*G + 0.114*B
        //对于一个int四字节，其彩色值存储方式为：BGRA
        int grayScale = (int)(ptr[4*i+2]*0.299 + ptr[4*i+1]*0.587 + ptr[4*i+0]*0.114);
        ptr[4*i+1] = grayScale;
        ptr[4*i+2] = grayScale;
        ptr[4*i+0] = grayScale;
    }

    int size = w * h;
    jintArray result = env->NewIntArray(size);
    env->SetIntArrayRegion(result, 0, size, cbuf);
    env->ReleaseIntArrayElements(buf, cbuf, 0);
    return result;
}
//复制代码
//
//        然后在 activity 页面里显示处理过的图片，如下：
//复制代码
//public class MainActivity extends AppCompatActivity {
//
//@Override
//protected void onCreate(Bundle savedInstanceState) {
//    super.onCreate(savedInstanceState);
//    setContentView(R.layout.activity_main);
//    NDKUtils ndk = new NDKUtils();
//
//    Bitmap bitmap = ((BitmapDrawable) getResources().getDrawable(
//            R.mipmap.pic_test)).getBitmap();
//    int w = bitmap.getWidth(), h = bitmap.getHeight();
//    int[] pix = new int[w * h];
//    bitmap.getPixels(pix, 0, w, 0, 0, w, h);
//    int [] resultPixes=ndk.gray(pix,w,h);
//    Bitmap result = Bitmap.createBitmap(w,h, Bitmap.Config.RGB_565);
//    result.setPixels(resultPixes, 0, w, 0, 0,w, h);
//
//    ImageView img = (ImageView)findViewById(R.id.img2);
//    img.setImageBitmap(result);
//
//}

//}
