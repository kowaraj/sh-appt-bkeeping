//module.exports.
function init () {
    console.log('hi');
    var neo4j = require('neo4j');
    var db = new neo4j.GraphDatabase('http://neo4j:1234@localhost:7474');

    db.cypher({
	query: 'CREATE (ee:Person { name: "Emil1", from: "Sweden", klout: 91 })',
    }, function (err, results) {
	console.log('...');
    });

    db.cypher({
	query: 'CREATE (ee:Person { name: "Emil3", from: "Sweden", klout: 93 })',
    }, function (err, results) {
	console.log('...');
    });

    db.cypher({
	query: 'MATCH (ee:Person) WHERE ee.name = "Emil3" RETURN ee',
	
    }, function (err, results) {
	if (err) throw err;
	var result = results[0];
	if (!result) {
            console.log('No user found.');
	} else {
            var user = result['ee'];
            console.log(JSON.stringify(user, null, 4));
	}
    });
    console.log('bye');

};



function x () {
   console.log('!!! jstest.js: x() called!');
};

var y = 5;

export { x, init, y };
//export { y };


