package com.syh.ndkdemo;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

@SuppressLint("SdCardPath") public class MainActivity extends Activity {
	
	static{
		System.loadLibrary("hello");
	}
	
	public static native String getStringFromC();
	
	public static native void sendStringToC(String filepath);

	
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		initViews();
	}
	
	private void initViews(){
		TextView tv = (TextView) findViewById(R.id.tv_info);
		tv.setText(getStringFromC());
		sendStringToC("/mnt/sdcard/boys.txt");
		Button send = (Button) findViewById(R.id.btn_sendtoc);
		send.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				sendStringToC("/mnt/sdcard/boys.txt");
			}
		});
	}
}
