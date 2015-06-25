(function () {
    var KEYS = {
        K_A: 65,
        K_B: 66,
        K_C: 67,
        K_D: 68,
        K_E: 69,
        K_F: 70,
        K_G: 71,
        K_H: 72,
        K_I: 73,
        K_J: 74,
        K_K: 75,
        K_L: 76,
        K_M: 77,
        K_N: 78,
        K_O: 79,
        K_P: 80,
        K_Q: 81,
        K_R: 82,
        K_S: 83,
        K_T: 84,
        K_U: 85,
        K_V: 86,
        K_W: 87,
        K_X: 88,
        K_Y: 89,
        K_Z: 90,
        K_LEFT: 37,
        K_RIGHT: 39,
        K_UP: 38,
        K_DOWN: 40,
        K_SPACE: 32,
        K_ESC: 27,
        K_PGUP: 33,
        K_PGDOWN: 34,
        K_HOME: 36,
        K_END: 35,
        K_0: 48,
        K_1: 49,
        K_2: 50,
        K_3: 51,
        K_4: 52,
        K_5: 53,
        K_6: 54,
        K_7: 55,
        K_8: 56,
        K_9: 57
    };

    var CANVAS_WIDTH = 400, CANVAS_HEIGHT = 400, ITEM_SIZE = 10;

    var initTime, canvas, ctx, mainLoopId, isGameOver = false;

    function fetchKeyboard(e) {
        console.log(e.keyCode);
        if (!isGameOver &&e.keyCode === KEYS.K_Q) {
            isGameOver = true;
        }
    }

    function initGame() {
        window.document.onkeydown = fetchKeyboard;
        canvas = document.getElementById("pacWorld");
        ctx = canvas.getContext("2d");
        ctx.font = "20px Arial";
        ctx.textAlign = "center";
    }

    function updateGame(dt) {

    }

    function drawGame(dt) {
        ctx.fillText(dt, 150, 50);
    }

    function gameOver(dt) {
        ctx.fillText("Game Over!", 150, 50);
    }

    function startGame() {
        var ONE_FRAME_TIME = 1000 / 60 ;
        var mainloop = function() {
            var currentTime = new Date().getTime();
            var dt = currentTime - initTime;

            ctx.clearRect(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
            if (isGameOver) {
                gameOver(dt);
                clearInterval(mainLoopId);
            } else{
                updateGame(dt);
                drawGame(dt);
            }
        };
        mainLoopId = setInterval(mainloop, ONE_FRAME_TIME);
    }

    window.onload = function () {
        initTime = new Date().getTime();
        initGame();
        startGame();
    };
})();