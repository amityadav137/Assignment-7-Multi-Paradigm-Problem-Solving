(* Calculate mean, median, and mode of an integer list in a purely functional style *)

let mean lst =
  let sum = List.fold_left (+) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let n = List.length sorted in
  if n mod 2 = 0 then
    let a = List.nth sorted (n / 2 - 1) in
    let b = List.nth sorted (n / 2) in
    float_of_int (a + b) /. 2.0
  else
    float_of_int (List.nth sorted (n / 2))

let mode lst =
  let table = Hashtbl.create (List.length lst) in
  List.iter (fun x ->
    let cnt = try Hashtbl.find table x with Not_found -> 0 in
    Hashtbl.replace table x (cnt + 1)
  ) lst;
  let max_count =
    Hashtbl.fold (fun _ v acc -> if v > acc then v else acc) table 0
  in
  Hashtbl.fold (fun k v acc ->
    if v = max_count then k :: acc else acc
  ) table []

(* Example usage *)
let () =
  let data = [5; 1; 2; 2; 3] in
  Printf.printf "Mean: %.2f\n" (mean data);
  Printf.printf "Median: %.2f\n" (median data);
  Printf.printf "Mode: ";
  List.iter (Printf.printf "%d ") (mode data);
  print_newline ()
