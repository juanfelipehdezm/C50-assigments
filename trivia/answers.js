// Run the script once the DOM is loaded
document.addEventListener("DOMContentLoaded", 
function()
{
    //when correct answer is clicked, chage color to green
    //when the button with the correct answer is clicked create a anonymus function
    let correct = document.querySelector(".correct");
    correct.addEventListener("click",
    function() 
        {
            //change the color background of .correct html correct class
            correct.style.background = "green";
            //select the html element with the id = #feedback and write in it (innerHTML)
            document.querySelector("#feedback1").innerHTML = "Correct!";
        });

    //when any incorrect answer is clicked, chand color to red
    //the selectorall return an array with all the elements selected that have the .incorrect class
    let incorrects = document.querySelectorAll(".incorrect");
    for (let i = 0; i < incorrects.length; i++) 
    {
        incorrects[i].addEventListener("click",
        function()
        {
            incorrects[i].style.background = "red";
            document.querySelector("#feedback1").innerHTML = "Incorrect!";
        });
    }
    //Check free response submission
    let check = document.querySelector("#checkAnswer")
    check.addEventListener("click",
    function()
    {
        let input = document.querySelector("input");
        if (input.value === "Russia")
        {
            input.style.background = "green";
            document.querySelector("#feedback2").innerHTML = "Correct!";
        }
        else
        {
            input.style.background = "red";
            document.querySelector("#feedback2").innerHTML = "Incorrect!";
        }
    });
});



