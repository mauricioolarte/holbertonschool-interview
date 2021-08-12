#!/usr/bin/node

const request = require('request');

const film = process.argv;

const url = 'https://swapi-api.hbtn.io/api/films/' + film[2];

request(url, function (error, response, body) {
  if (error) {
    return;
  }
  const res = JSON.parse(body);

  async function asyncRequest (url) {
    return new Promise((resolve, reject) => {
      request(url, (error, response, body) => {
        resolve({ error, response, body });
      });
    });
  }

  async function printNames (arrayUrls) {
    for (const url of arrayUrls) {
      const response = await asyncRequest(url);
      const body = JSON.parse(response.body);
      console.log(body.name);
    }
  }
  printNames(res.characters);
});
