const express = require("express");
const cors = require('cors');
const app = express();
var performance = require('perf_hooks').performance;
const { aabb } = require('./build/Release/result');

app.use(express.json())
app.use(cors());

app.set('host', '127.0.0.1');

app.listen(3000, () => {
    console.log('listen')
});

//Обраховую час і результат алгоритмуliste
app.post("/calculate", (req, res) => {

    const { firstFigure, secondFigure } = req.body;

    var t1 = performance.now();
    const cppResult = aabb({ "firstFigureX": firstFigure.x, "firstFigureY": firstFigure.y, "firstFigureWidth": firstFigure.width, "firstFigureHeight": firstFigure.height }, { "secondFigureX": secondFigure.x, "secondFigureY": secondFigure.y, "secondFigureWidth": secondFigure.width, "secondFigureHeight": secondFigure.height });
    const cppTime = performance.now() - t1;

    t1 = performance.now();
    const jsResult = check(firstFigure, secondFigure);
    const jsTime = performance.now() - t1;
    
    // Надсилаю результати для клієнта
    res.send({ code: 200, results: {js: { time: jsTime, result: jsResult }, cpp: { time: cppTime, result: cppResult }} });
});

app.get('/', (req, res)=>{
    res.send({code: 200, msg: 'privet'});
})





function check(firstFigure, secondFigure) {
    if (firstFigure.x < secondFigure.x + secondFigure.width &&
        firstFigure.x + firstFigure.width > secondFigure.x &&
        firstFigure.y < secondFigure.y + secondFigure.height &&
        firstFigure.y + firstFigure.height > secondFigure.y) {
        return true;
    } else return false;
}