const express = require('express');
const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');
const path = require('path');

const app = express();
const portNumber = 3000;

app.use(express.static(__dirname));

const port = new SerialPort({
  path: 'COM9', // Update accordingly
  baudRate: 9600,
});

const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));

let leftData = { angle: 0, distance: 0 };
let rightData = { angle: 0, distance: 0 };

parser.on('data', (data) => {
  try {
    const parts = data.trim().split(';');
    if (parts.length === 2) {
      const [left, right] = parts;
      const [lAngle, lDist] = left.replace('L:', '').split(',').map(Number);
      const [rAngle, rDist] = right.replace('R:', '').split(',').map(Number);

      leftData = { angle: lAngle, distance: lDist };
      rightData = { angle: rAngle, distance: rDist };

      console.log(`Left -> Angle: ${lAngle}, Distance: ${lDist}`);
      console.log(`Right -> Angle: ${rAngle}, Distance: ${rDist}`);
    }
  } catch (err) {
    console.error('Parse error:', err);
  }
});

app.get('/distance', (req, res) => {
  res.json({ left: leftData, right: rightData });
});

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

app.listen(portNumber, '0.0.0.0', () => {
  console.log(`Server running at http://172.20.158.35:${portNumber}`);
});
