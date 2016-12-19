/* var addon = require('bindings')('demo'); this can be var addon = require('bindings')('demo.node');
 * demo.node or demo name is depend on  binding gyp configuration 
 * 
 * */

var addon = require('bindings')('demo'); // 

var s = addon.lemo();

 console.log(s);