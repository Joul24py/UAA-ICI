package com.example.fx05;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {
    private EditText text1;
    private EditText text2;
    private TextView result;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        text1 = (EditText) findViewById(R.id.inputValue1);
        text2 = (EditText) findViewById(R.id.inputValue2);
        result = (TextView) findViewById(R.id.result);
    }

    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.button1:
                RadioButton celsiusButton = (RadioButton) findViewById(R.id.radio0);
                RadioButton fahrenheitButton = (RadioButton) findViewById(R.id.radio1);

                float inputValue1 = Float.parseFloat(text1.getText().toString());
                float inputValue2 = Float.parseFloat(text2.getText().toString());
                if (celsiusButton.isChecked()) {
                    result.setText(String
                            .valueOf(ConverterUtil.Sumar(inputValue1, inputValue2)));
                    fahrenheitButton.setChecked(false);
                    celsiusButton.setChecked(false);
                } else {
                    result.setText(String
                            .valueOf(ConverterUtil.Restar(inputValue1, inputValue2)));
                    fahrenheitButton.setChecked(false);
                    celsiusButton.setChecked(false);
                }
                break;
        }
    }
}