document.addEventListener("DOMContentLoaded",
function()
{
    let answer = document.querySelector(".btn-outline-secondary");
    answer.addEventListener("click",
    function()
    {
        document.querySelector("#machineL").innerHTML = "Machine Learning is the science (and art) of programming computers so they can learn from data.";
    });
});