const addon = require('./build/Release/addon');

const addNumbersAddon = addon.addNumbers;

const addNumbersNode = (value, count) => {
 let result = 0;
 for (let i = 0; i < count; i++) {
   result += value;
 }
 return result;
};

const addNumbers = (number, addingTimes) => {
 console.time('C++');
 console.log(addNumbersAddon(number, addingTimes));
 console.timeEnd('C++');

 console.log('>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>');

 console.time('JS');
 console.log(addNumbersNode(number, addingTimes));
 console.timeEnd('JS');
};

addNumbers(3.14, 1000000000);
