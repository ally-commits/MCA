import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css'],
})
export class AppComponent {
  title = 'my-app';
  getVal(e : any) {
    let value = e.target.value.split("");
    let sum = 0;
    value.forEach((str: any) => {
      sum += str.charCodeAt(0);
    });
    alert(sum);
  }
}
