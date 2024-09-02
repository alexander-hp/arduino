package com.example.controlbluetooth

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle

//aaaaaaaa
import android.Manifest
import android.bluetooth.BluetoothAdapter
import android.bluetooth.BluetoothDevice
import android.bluetooth.BluetoothManager
import android.bluetooth.BluetoothSocket
import android.content.ContentValues.TAG
import android.content.Context
import android.content.Intent
import android.content.pm.PackageManager
import android.os.Handler
import android.os.Looper
import android.os.Message
import android.util.Log
import android.widget.*
import androidx.activity.result.contract.ActivityResultContracts.StartActivityForResult
import androidx.core.app.ActivityCompat
import java.io.IOException
import java.util.*
//aaaaaaaa
//bbbbbbbb
const val REQUEST_ENABLE_BT = 1
//bbbbbbbb

class MainActivity : AppCompatActivity() {
    //cccccccc
    //BluetoothAdapter
    lateinit var mBtAdapter: BluetoothAdapter
    var mAddressDevices: ArrayAdapter<String>? = null
    var mNameDevices: ArrayAdapter<String>? = null
    private var connectedThread: ConnectedThread? = null


    companion object{
        var m_myUUID: UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB")
        private var m_bluetoothSocket: BluetoothSocket? = null

        var m_isConnected: Boolean = false
        lateinit var m_address: String

        const val MESSAGE_READ: Int = 0
        const val TAG = "BluetoothService"
    }
    //cccccccc

    //Nuevo Codigo

    // Agregar un TextView para mostrar datos recibidos
    lateinit var mTextViewReceive: TextView

    // fin nuevo codigo

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        //ddddddddd
        mAddressDevices = ArrayAdapter( this, android.R.layout.simple_list_item_1)
        mNameDevices = ArrayAdapter(this, android.R.layout.simple_list_item_1)

        val idBtnOnBT = findViewById<Button>(R.id.idBtnOnBT)
        val idBtnOffBT = findViewById<Button>(R.id.idBtnOffBT)
        val idBtnConect = findViewById<Button>(R.id.idBtnConect)
        val idBtnEnviar = findViewById<Button>(R.id.idBtnEnviar)

        val idBtnLuz_1on = findViewById<Button>(R.id.idBtnLuz_1on)
        val idBtnLuz_1off = findViewById<Button>(R.id.idBtnLuz_1off)
        val idBtnLuz_2on = findViewById<Button>(R.id.idBtnLuz_2on)
        val idBtnLuz_2off = findViewById<Button>(R.id.idBtnLuz_2off)

        val idBtnDispBT = findViewById<Button>(R.id.idBtnDispBT)
        val idSpinDisp = findViewById<Spinner>(R.id.idSpinDisp)
        val idTextOut = findViewById<EditText>(R.id.idTextOut)
        mTextViewReceive = findViewById(R.id.textView5)
        //------------
        //------------
        val someActivityResultLauncher = registerForActivityResult(
            StartActivityForResult()
        ) { result ->
            if (result.resultCode == REQUEST_ENABLE_BT){
                Log.i("Main Activity", "ACTIVIDAD REGISTRADA")
            }
        }
        //Inicializacion del bluetooth adapter
        mBtAdapter = (getSystemService(Context.BLUETOOTH_SERVICE) as BluetoothManager).adapter

        //Checar si esta prendido o apagado
        if(mBtAdapter == null){
            Toast.makeText(this,  "Bluetooth no esta disponible en este dispositivo", Toast.LENGTH_LONG).show()
        } else {
            Toast.makeText(this,  "Bluetooth esta disponible en este dispositivo", Toast.LENGTH_LONG).show()
        }
        //---------
        //---------

        //Boton Encender bluetooth
        idBtnOnBT.setOnClickListener {
            if(mBtAdapter.isEnabled){
                //Si ya esta activado
                Toast.makeText(this, "Bluetooth ya se encuentra activado", Toast.LENGTH_LONG).show()
            } else {
                // Encender bluetooth
                val enableBtIntent = Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE)
                if (ActivityCompat.checkSelfPermission(
                        this,
                        Manifest.permission.BLUETOOTH_CONNECT
                    ) != PackageManager.PERMISSION_GRANTED
                )  {
                    Log.i("MainActivity", "ActivityCompat#requestPermissions")
                }
                someActivityResultLauncher.launch(enableBtIntent)
            }
        }

        //Boton Apagar Bluetooth
        idBtnOffBT.setOnClickListener {
            if(!mBtAdapter.isEnabled) {
                //Si ya esta desactivado
                Toast.makeText(this, "Bluetooth ya se encuentra desactivado", Toast.LENGTH_LONG).show()
            } else {
                //Apagar Bluetooth
                mBtAdapter.disable()
                Toast.makeText(this, "Se ha desactivado el bluetooth", Toast.LENGTH_LONG).show()
            }
        }

        //Boton dispositivos emparejados
        idBtnDispBT.setOnClickListener {
            if(mBtAdapter.isEnabled){

                val pairedDevices: Set<BluetoothDevice>? = mBtAdapter?.bondedDevices
                mAddressDevices!!.clear()
                mNameDevices!!.clear()

                pairedDevices?.forEach { device ->
                    val deviceName = device.name
                    val deviceHardwareAddress = device.address
                    mAddressDevices!!.add(deviceHardwareAddress)
                    // .... EN ESTE PUNTO GUARDO LOS NOMBRE A MOSTRARSE EN EL COMBO
                    mNameDevices!!.add(deviceName)
                }

                //Actualizar los dispositivos
                idSpinDisp.setAdapter(mNameDevices)
            } else {
                val noDevices = "Ningun dispositivo pudo ser emparejado"
                mAddressDevices!!.add(noDevices)
                mNameDevices!!.add(noDevices)
                Toast.makeText(this,"Primero vincule un dispositivo bluetooth", Toast.LENGTH_LONG).show()
            }
        }

        idBtnConect.setOnClickListener{
            try{
                if(m_bluetoothSocket == null || !m_isConnected){

                    val IntValSpin = idSpinDisp.selectedItemPosition
                    m_address = mAddressDevices!!.getItem(IntValSpin).toString()
                    Toast.makeText(this, m_address, Toast.LENGTH_LONG).show()
                    //cancel discovery bc it otherwise slows down the connection
                    mBtAdapter?.cancelDiscovery()
                    val device: BluetoothDevice = mBtAdapter.getRemoteDevice(m_address)
                    m_bluetoothSocket = device.createInsecureRfcommSocketToServiceRecord(m_myUUID)
                    m_bluetoothSocket!!.connect()

                    connectedThread = ConnectedThread(m_bluetoothSocket!!)
                    connectedThread!!.start()
                    m_isConnected = true
                }

                Toast.makeText(this, "CONEXION EXITOSA", Toast.LENGTH_LONG).show()
                Log.i("MainActivity", "CONEXION EXITOSA")

            } catch (e: IOException){
                //conectSuccess
                e.printStackTrace()
                Toast.makeText(this, "ERROR DE CONEXION", Toast.LENGTH_LONG).show()
                Log.i("MainActivity", "ERROR DE CONEXION")
            }
        }

        idBtnLuz_1on.setOnClickListener {
            sendCommand("A")
        }

        idBtnLuz_1off.setOnClickListener {
            sendCommand("B")
        }

        idBtnLuz_2on.setOnClickListener {
            sendCommand("C")
        }

        idBtnLuz_2off.setOnClickListener {
            sendCommand("D")
        }

        idBtnEnviar.setOnClickListener {
            if(idTextOut.text.toString().isEmpty()){
                Toast.makeText(this, "El nombre no puede estar vacio", Toast.LENGTH_SHORT)
            } else{
                var mensaje_out: String = idTextOut.text.toString()
                sendCommand(mensaje_out)
            }
        }
        //ddddddddd
    }
    //eeeeeee
    private fun sendCommand(input: String){
        // checa si ya tienes conexion en bluetooth
        if(m_bluetoothSocket != null){
            try{
                m_bluetoothSocket!!.outputStream.write(input.toByteArray())
            } catch(e: IOException){
                e.printStackTrace()
            }
        }
    }
    //eeeeeee

    override fun onDestroy() {
        super.onDestroy()
        connectedThread?.cancel()
        m_bluetoothSocket?.close()
        m_isConnected = false
    }

    //Nuevo codigo ********************
    // Handler para gestionar los datos recibidos
    private val mHandler: Handler = object : Handler(Looper.getMainLooper()) {
        override fun handleMessage(msg: Message) {
            when (msg.what) {
                MESSAGE_READ -> {
                    val readBuf = msg.obj as ByteArray
                    val readMessage = String(readBuf, 0, msg.arg1)
                    mTextViewReceive.append(readMessage + "\n")
                    //mTextViewReceive.text = readMessage
                }
            }
        }
    }


    // Clase para manejar la conexión y recepción de datos en un hilo separado
    private inner class ConnectedThread(private val mmSocket: BluetoothSocket) : Thread() {
        private val mmInStream = mmSocket.inputStream
        private val mmBuffer: ByteArray = ByteArray(1024)

        override fun run() {
            var numBytes: Int

            while (true) {
                // Leer del InputStream
                numBytes = try {
                    mmInStream.read(mmBuffer)
                } catch (e: IOException) {
                    Log.d(TAG, "Input stream was disconnected", e)
                    break
                }

                // Enviar los bytes obtenidos al UI thread
                val readMsg = mHandler.obtainMessage(
                    MESSAGE_READ, numBytes, -1,
                    mmBuffer.copyOf(numBytes)
                )
                readMsg.sendToTarget()
            }
        }

        // ... (El resto de tu código aquí para la función cancel)
        fun cancel() {
            try {
                mmSocket.close()
            } catch (e: IOException) {
                Log.e(TAG, "Could not close the client socket", e)
            }
        }
    }


}