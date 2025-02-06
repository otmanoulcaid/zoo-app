
document.addEventListener("DOMContentLoaded", ()=>
{
	let addBtn = document.querySelector('a.btn');
	addBtn.addEventListener("click", addXmlNode);
	//redirect the user to the page of animals after adding it
});

async function addXmlNode()
{
    const animalData = {
		path: document.querySelector("#path").value.trim(),
		id: document.querySelector("#id").value.trim(),
		name: document.querySelector("#name").value.trim(),
		espece: document.querySelector("#espece").value.trim(),
		race: document.querySelector("#race").value.trim(),
		age: document.querySelector("#age").value.trim(),
		proprietaire: document.querySelector("#proprietaire").value.trim(),
		description: document.querySelector("#description").value.trim(),
	};
	const animalXML = `
<animal>
	<path>${animalData.path}</path>
	<id>${animalData.id}</id>
	<name>${animalData.name}</name>
	<espece>${animalData.espece}</espece>
	<race>${animalData.race}</race>
	<description>${animalData.description}</description>
	<age>${animalData.age}</age>
	<proprietaire>${animalData.proprietaire}</proprietaire>
</animal>
		`;

	console.log("Animal Data:", animalData);

	fetch("http://nginx/writer", { //docker compose resolve the container name using DNS
		method: "POST",
		headers: {
			"Content-Type": "application/json"
		},
		body: animalXML
	})
	.then(response => response.text())
	.then(data => {
		console.log(data);
		let container = document.getElementById("container")
		container.innerHTML = data;
	})
	.catch(error => document.getElementById("body").innerHTML = error);
}
